//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <QtGui/QTransform>
#include "GOPropertyNames.hpp"
#include "GOPropertyValues.hpp"
#include "GOImage.hpp"
#include "GOAxis.hpp"
#include "GODataMappingModeProperty.hpp"
#include "GOMappingModeProperty.hpp"
#include "GOStringOnOffProperty.hpp"
#include "GOVectorTwoDoubleProperty.hpp"
#include "GOGObjectsProperty.hpp"
#include "GOGObjectsProperty.hpp"
#include "GOArrayOfProperty.hpp"
#include "MinMaxHelpers.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
std::wstring
GOImage::getType()
{
    return L"image";
}
//=============================================================================
GOImage::GOImage()
{
    constructProperties();
    setupDefaults();
}
//=============================================================================
void
GOImage::constructProperties()
{
    registerProperty(new GOVectorProperty, GO_ALPHA_DATA_PROPERTY_NAME_STR);
    registerProperty(new GOArrayOfProperty, GO_C_DATA_PROPERTY_NAME_STR);
    registerProperty(new GOMappingModeProperty, GO_ALPHA_DATA_MAPPING_PROPERTY_NAME_STR);
    registerProperty(new GODataMappingModeProperty, GO_C_DATA_MAPPING_PROPERTY_NAME_STR);
    registerProperty(new GOGObjectsProperty, GO_CHILDREN_PROPERTY_NAME_STR);
    registerProperty(new GOGObjectsProperty, GO_PARENT_PROPERTY_NAME_STR);
    registerProperty(new GOStringProperty, GO_TAG_PROPERTY_NAME_STR);
    registerProperty(new GOStringProperty, GO_TYPE_PROPERTY_NAME_STR);
    registerProperty(new GOTwoVectorProperty, GO_X_DATA_PROPERTY_NAME_STR);
    registerProperty(new GOTwoVectorProperty, GO_Y_DATA_PROPERTY_NAME_STR);
    registerProperty(new GOArrayOfProperty, GO_USER_DATA_PROPERTY_NAME_STR);
    registerProperty(new GOOnOffProperty, GO_VISIBLE_PROPERTY_NAME_STR);
    sortProperties();
}
//=============================================================================
void
GOImage::setupDefaults()
{
    GOVectorProperty* hp = (GOVectorProperty*)findProperty(GO_ALPHA_DATA_PROPERTY_NAME_STR);
    std::vector<double> gp;
    gp.push_back(1.0);
    hp->data(gp);
    setRestrictedStringDefault(GO_ALPHA_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_NONE_STR);
    setRestrictedStringDefault(GO_C_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_DIRECT_STR);
    setStringDefault(GO_TYPE_PROPERTY_NAME_STR, getType());
    setTwoVectorDefault(GO_X_DATA_PROPERTY_NAME_STR, 0, 1);
    setTwoVectorDefault(GO_Y_DATA_PROPERTY_NAME_STR, 0, 1);
    setRestrictedStringDefault(GO_VISIBLE_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_ON_STR);
}
//=============================================================================
GOImage::~GOImage() { }
//=============================================================================
std::vector<double>
GOImage::getLimits()
{
    GOTwoVectorProperty* xp = (GOTwoVectorProperty*)findProperty(GO_X_DATA_PROPERTY_NAME_STR);
    GOTwoVectorProperty* yp = (GOTwoVectorProperty*)findProperty(GO_Y_DATA_PROPERTY_NAME_STR);
    std::vector<double> XP(xp->data());
    std::vector<double> YP(xp->data());

    std::vector<double> limits;
    if (XP.size() != 2 || YP.size() != 2) {
        return limits;
    }
    limits.push_back(xp->data()[0]);
    limits.push_back(xp->data()[1]);
    limits.push_back(yp->data()[0]);
    limits.push_back(yp->data()[1]);
    limits.push_back(0);
    limits.push_back(0);

    ArrayOf cdata(findArrayOfProperty(GO_C_DATA_PROPERTY_NAME_STR));
    if (!cdata.isEmpty()) {
        cdata.promoteType(NLS_DOUBLE);
        limits.push_back(ArrayOfMin(cdata));
        limits.push_back(ArrayOfMax(cdata));
    } else {
        limits.push_back(0);
        limits.push_back(1);
    }
    std::vector<double> alphadata(findVectorDoubleProperty(GO_ALPHA_DATA_PROPERTY_NAME_STR));
    limits.push_back(findVectorMin(alphadata));
    limits.push_back(findVectorMax(alphadata));
    return limits;
}
//=============================================================================
void
GOImage::updateCAlphadata()
{
    ArrayOf cdata(findArrayOfProperty(GO_C_DATA_PROPERTY_NAME_STR));
    if (cdata.isEmpty()) {
        return;
    }
    bool cdata_is_integer = cdata.isIntegerValue();
    cdata.promoteType(NLS_DOUBLE);
    std::vector<double> alphas(getAlphaMap(cdata.getRows(), cdata.getColumns()));
    if ((cdata.getDimensions().getLength() == 3) && (cdata.getDimensionLength(2) == 3)) {
        prepareImageRGBNoAlphaMap((const double*)cdata.getDataPointer(), cdata.getRows(),
            cdata.getColumns(), alphas, cdata_is_integer);
    } else {
        double* dp = RGBExpandImage((const double*)cdata.getDataPointer(), cdata.getRows(),
            cdata.getColumns(), !cdata_is_integer);
        prepareImageRGBNoAlphaMap(dp, cdata.getRows(), cdata.getColumns(), alphas, false);
        delete[] dp;
    }
}
//=============================================================================
void
GOImage::updateState()
{
    GOAxis* ax = getParentAxis();
    GOFigure* fig = getParentFigure();
    if (hasChanged(GO_C_DATA_PROPERTY_NAME_STR) || ax->hasChanged(GO_C_LIM_PROPERTY_NAME_STR)
        || fig->hasChanged(GO_COLOR_MAP_PROPERTY_NAME_STR)
        || ax->hasChanged(GO_COLOR_MAP_PROPERTY_NAME_STR)
        || hasChanged(GO_C_DATA_MAPPING_PROPERTY_NAME_STR)) {
        updateCAlphadata();
    }
    ArrayOf cdata(findArrayOfProperty(GO_C_DATA_PROPERTY_NAME_STR));
    GOTwoVectorProperty* xp = (GOTwoVectorProperty*)findProperty(GO_X_DATA_PROPERTY_NAME_STR);
    if (xp->data().empty()) {
        if (cdata.getColumns() > 1) {
            setTwoVectorDefault(GO_X_DATA_PROPERTY_NAME_STR, 0, cdata.getColumns());
        } else {
            setTwoVectorDefault(GO_X_DATA_PROPERTY_NAME_STR, 0, 1);
        }
    }
    GOTwoVectorProperty* yp = (GOTwoVectorProperty*)findProperty(GO_Y_DATA_PROPERTY_NAME_STR);
    if (yp->data().empty()) {
        if (cdata.getRows() > 1) {
            setTwoVectorDefault(GO_Y_DATA_PROPERTY_NAME_STR, 0, cdata.getRows());
        } else {
            setTwoVectorDefault(GO_Y_DATA_PROPERTY_NAME_STR, 0, 1);
        }
    }
    clearAllChanged();
}
//=============================================================================
void
GOImage::paintMe(RenderInterface& gc)
{
    if (stringCheck(GO_VISIBLE_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_OFF_STR)) {
        return;
    }
    GOTwoVectorProperty* xp = (GOTwoVectorProperty*)findProperty(GO_X_DATA_PROPERTY_NAME_STR);
    GOTwoVectorProperty* yp = (GOTwoVectorProperty*)findProperty(GO_Y_DATA_PROPERTY_NAME_STR);
    int x1, y1, x2, y2;
    std::vector<double> XP(xp->data());
    std::vector<double> YP(yp->data());
    if (XP.size() != 2 || YP.size() != 2) {
        return;
    }
    gc.toPixels(xp->data()[0], yp->data()[0], 0, x1, y1);
    gc.toPixels(xp->data()[1], yp->data()[1], 0, x2, y2);
    if ((abs(x2 - x1) > 4096) || (abs(y2 - y1) > 4096)) {
        return;
    }
    gc.drawImage(xp->data()[0], yp->data()[0], xp->data()[1], yp->data()[1],
        img.scaled(abs(x2 - x1), abs(y2 - y1)));
}
//=============================================================================
std::vector<double>
GOImage::getAlphaMap(indexType rows, indexType cols)
{
    GOVectorProperty* hp = (GOVectorProperty*)findProperty(GO_ALPHA_DATA_PROPERTY_NAME_STR);
    std::vector<double> alphain(hp->data());
    std::vector<double> alphaout;
    std::vector<double> amap(((GraphicsObject*)getParentFigure())
                                 ->findVectorDoubleProperty(GO_ALPHA_MAP_PROPERTY_NAME_STR));
    indexType amaplen((indexType)amap.size());
    GOAxis* ap(getParentAxis());
    std::vector<double> alim(
        ((GraphicsObject*)ap)->findVectorDoubleProperty(GO_A_LIM_PROPERTY_NAME_STR));
    double alim_min(std::min(alim[0], alim[1]));
    double alim_max(std::max(alim[0], alim[1]));
    int increment;
    if (alphain.size() == 0) {
        for (indexType i = 0; i < rows * cols; i++) {
            alphaout.push_back(1);
        }
        return alphaout;
    } else if (alphain.size() != rows * cols) {
        increment = 0;
    } else
        increment = 1;
    if (stringCheck(GO_ALPHA_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_NONE_STR)) {
        for (int i = 0; i < rows * cols; i++) {
            alphaout.push_back(std::min(1.0, std::max(0.0, alphain[i * increment])));
        }
    } else if (stringCheck(GO_ALPHA_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_DIRECT_STR)) {
        for (int i = 0; i < rows * cols; i++) {
            indexType ndx = (indexType)alphain[i * increment] - 1;
            ndx = std::min<indexType>(amaplen - 1, std::max<indexType>(0, ndx));
            alphaout.push_back(amap[ndx]);
        }
    } else {
        for (indexType i = 0; i < rows * cols; i++) {
            indexType ndx = (indexType)alphain[i * increment] - 1;
            ndx = (indexType)((alphain[i * increment] - alim_min) / (alim_max - alim_min)
                * (amaplen - 1));
            ndx = std::min<indexType>(amaplen - 1, std::max<indexType>(0, ndx));
            alphaout.push_back(amap[ndx]);
        }
    }
    return alphaout;
}
//=============================================================================
double*
GOImage::RGBExpandImage(const double* dp, indexType rows, indexType cols, bool floatData)
{
    double* ret = new double[rows * cols * 3];
    GOAxis* ap(getParentAxis());
    std::vector<double> cmap(
        ((GraphicsObject*)ap)->findVectorDoubleProperty(GO_COLOR_MAP_PROPERTY_NAME_STR));
    std::vector<double> clim(
        ((GraphicsObject*)ap)->findVectorDoubleProperty(GO_C_LIM_PROPERTY_NAME_STR));
    double clim_min(std::min(clim[0], clim[1]));
    double clim_max(std::max(clim[0], clim[1]));
    if (std::fabs(clim_min - clim_max) < std::numeric_limits<double>::epsilon()) {
        return ret;
    }
    size_t cmaplen(cmap.size() / 3);
    if (cmaplen < 1) {
        if (stringCheck(GO_C_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_DIRECT_STR)) {
            for (int i = 0; i < rows * cols; i++) {
                int ndx = floatData ? (int)dp[i] - 1 : (int)dp[i];
                ndx = (int)std::min<indexType>(
                    (indexType)(cmaplen - 1), std::max<indexType>((indexType)0, (indexType)ndx));
                ret[i] = 1;
                ret[i + rows * cols] = 1;
                ret[i + 2 * rows * cols] = 1;
            }
        } else {
            for (int i = 0; i < rows * cols; i++) {
                int ndx = (int)((dp[i] - clim_min) / (clim_max - clim_min) * (cmaplen - 1));
                ndx = (int)std::min<indexType>(cmaplen - 1, std::max(0, ndx));
                ret[i] = 1;
                ret[i + rows * cols] = 1;
                ret[i + 2 * rows * cols] = 1;
            }
        }
        return ret;
    }
    if (stringCheck(GO_C_DATA_MAPPING_PROPERTY_NAME_STR, GO_PROPERTY_VALUE_DIRECT_STR)) {
        for (int i = 0; i < rows * cols; i++) {
            int ndx = floatData ? (int)dp[i] - 1 : (int)dp[i];
            ndx = (int)std::min<indexType>(
                (indexType)(cmaplen - 1), std::max<indexType>((indexType)0, (indexType)ndx));
            ret[i] = cmap[3 * ndx];
            ret[i + rows * cols] = cmap[3 * ndx + 1];
            ret[i + 2 * rows * cols] = cmap[3 * ndx + 2];
        }
    } else {
        for (int i = 0; i < rows * cols; i++) {
            int ndx = (int)((dp[i] - clim_min) / (clim_max - clim_min) * (cmaplen - 1));
            ndx = (int)std::min<indexType>(cmaplen - 1, std::max(0, ndx));
            ret[i] = cmap[3 * ndx];
            ret[i + rows * cols] = cmap[3 * ndx + 1];
            ret[i + 2 * rows * cols] = cmap[3 * ndx + 2];
        }
    }
    return ret;
}
//=============================================================================
void
GOImage::prepareImageRGBNoAlphaMap(const double* dp, indexType rows, indexType cols,
    std::vector<double>& alpha, bool isIntegerData)
{
    img = QImage((int)cols, (int)rows, QImage::Format_ARGB32);
    for (indexType i = 0; i < rows; i++) {
        QRgb* ibits = (QRgb*)img.scanLine((int)i);
        for (indexType j = 0; j < cols; j++)
            if (!isIntegerData) {
                ibits[j] = qRgba((int)(255 * dp[(i + j * rows)]),
                    (int)(255 * dp[(i + j * rows) + rows * cols]),
                    (int)(255 * dp[(i + j * rows) + 2 * rows * cols]),
                    (int)(255 * alpha[i + j * rows]));
            } else {
                ibits[j] = qRgba((int)(dp[(i + j * rows)]), (int)(dp[(i + j * rows) + rows * cols]),
                    (int)(dp[(i + j * rows) + 2 * rows * cols]), (int)(255 * alpha[i + j * rows]));
            }
    }
}
//=============================================================================
}
//=============================================================================