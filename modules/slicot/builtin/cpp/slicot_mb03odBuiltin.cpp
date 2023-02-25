//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include <algorithm>
#include "slicot_mb03odBuiltin.hpp"
#include "Error.hpp"
#include "i18n.hpp"
#include "InputOutputArgumentsCheckers.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    mb03od_(const char* JOBQR, int* M, int* N, double* A, int* LDA, int* JPVT, double* RCOND,
        double* SVLMAX, double* TAU, int* RANK, double* SVAL, double* DWORK, int* LDWORK,
        int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, JPVT_OUT, TAU, RANK, SVAL, INFO] = slicot_mb03od(JOBQR, A_IN, JPVT_IN, RCOND, SVLMAX)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_mb03odBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 6);
    nargincheck(argIn, 5, 5);
    // INPUT VARIABLES
    ArrayOf JOBQR = argIn[0];
    Dimensions dimsJOBQR = JOBQR.getDimensions();
    std::string JOBQR_string = JOBQR.getContentAsCString();
    const char* JOBQR_ptr = JOBQR_string.c_str();
    ArrayOf RCOND = argIn[3];
    Dimensions dimsRCOND = RCOND.getDimensions();
    RCOND.promoteType(NLS_DOUBLE);
    double* RCOND_ptr = (double*)RCOND.getDataPointer();
    ArrayOf SVLMAX = argIn[4];
    Dimensions dimsSVLMAX = SVLMAX.getDimensions();
    SVLMAX.promoteType(NLS_DOUBLE);
    double* SVLMAX_ptr = (double*)SVLMAX.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[1];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double* A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf JPVT = argIn[2];
    Dimensions dimsJPVT = JPVT.getDimensions();
    JPVT.promoteType(NLS_INT32);
    ArrayOf JPVT_output = JPVT;
    JPVT_output.ensureSingleOwner();
    int* JPVT_output_ptr = (int*)JPVT_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)A.getRows();
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1, 3 * (int)A.getColumns() + 1);
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0] = 3 * (int)A.getColumns() + 1;
    // OUTPUT VARIABLES
    ArrayOf TAU_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)1, (indexType)std::min((int)A.getRows(), (int)A.getColumns()));
    double* TAU_output_ptr = (double*)TAU_output.getDataPointer();
    ArrayOf RANK_output = ArrayOf::int32VectorConstructor(1);
    int* RANK_output_ptr = (int*)RANK_output.getDataPointer();
    ArrayOf SVAL_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)3);
    double* SVAL_output_ptr = (double*)SVAL_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsJOBQR.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    Dimensions dimsA_expected(std::max(1, (int)A.getRows()), (int)A.getColumns());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #2: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsJPVT_expected(1, (int)A.getColumns());
    if (!dimsJPVT.equals(dimsJPVT_expected)) {
        Error(_("Input argument #3: wrong size.") + " " + dimsJPVT_expected.toString() + " "
            + "expected" + ".");
    }
    if (!dimsRCOND.isScalar()) {
        Error(_W("Input argument #4: scalar expected."));
    }
    if (!dimsSVLMAX.isScalar()) {
        Error(_W("Input argument #5: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try {
        mb03od_(JOBQR_ptr, M_ptr, N_ptr, A_output_ptr, LDA_ptr, JPVT_output_ptr, RCOND_ptr,
            SVLMAX_ptr, TAU_output_ptr, RANK_output_ptr, SVAL_output_ptr, DWORK_ptr, LDWORK_ptr,
            INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("mb03od function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval << A_output;
    }
    if (nLhs > 1) {
        retval << JPVT_output;
    }
    if (nLhs > 2) {
        retval << TAU_output;
    }
    if (nLhs > 3) {
        retval << RANK_output;
    }
    if (nLhs > 4) {
        retval << SVAL_output;
    }
    if (nLhs > 5) {
        retval << INFO_output;
    }
    return retval;
}
//=============================================================================
