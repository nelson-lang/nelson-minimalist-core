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
#include "slicot_sb02odBuiltin.hpp"
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
    sb02od_(const char* DICO, const char* JOBB, const char* FACT, const char* UPLO,
        const char* JOBL, const char* SORT, int* N, int* M, int* P, const double* A, int* LDA,
        const double* B, int* LDB, const double* Q, int* LDQ, const double* R, int* LDR,
        const double* L, int* LDL, double* RCOND, double* X, int* LDX, double* ALFAR, double* ALFAI,
        double* BETA, double* S, int* LDS, double* T, int* LDT, double* U, int* LDU, double* TOL,
        int* IWORK, double* DWORK, int* LDWORK, int* BWORK, int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [RCOND, X, ALFAR, ALFAI, BETA, S, T, U, INFO] = slicot_sb02od(DICO, JOBB, FACT, UPLO, JOBL, SORT,
// P, A, B, Q, R, L, TOL)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_sb02odBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 9);
    nargincheck(argIn, 13, 13);
    // INPUT VARIABLES
    ArrayOf DICO = argIn[0];
    Dimensions dimsDICO = DICO.getDimensions();
    std::string DICO_string = DICO.getContentAsCString();
    const char* DICO_ptr = DICO_string.c_str();
    ArrayOf JOBB = argIn[1];
    Dimensions dimsJOBB = JOBB.getDimensions();
    std::string JOBB_string = JOBB.getContentAsCString();
    const char* JOBB_ptr = JOBB_string.c_str();
    ArrayOf FACT = argIn[2];
    Dimensions dimsFACT = FACT.getDimensions();
    std::string FACT_string = FACT.getContentAsCString();
    const char* FACT_ptr = FACT_string.c_str();
    ArrayOf UPLO = argIn[3];
    Dimensions dimsUPLO = UPLO.getDimensions();
    std::string UPLO_string = UPLO.getContentAsCString();
    const char* UPLO_ptr = UPLO_string.c_str();
    ArrayOf JOBL = argIn[4];
    Dimensions dimsJOBL = JOBL.getDimensions();
    std::string JOBL_string = JOBL.getContentAsCString();
    const char* JOBL_ptr = JOBL_string.c_str();
    ArrayOf SORT = argIn[5];
    Dimensions dimsSORT = SORT.getDimensions();
    std::string SORT_string = SORT.getContentAsCString();
    const char* SORT_ptr = SORT_string.c_str();
    ArrayOf P = argIn[6];
    Dimensions dimsP = P.getDimensions();
    P.promoteType(NLS_INT32);
    int* P_ptr = (int*)P.getDataPointer();
    ArrayOf A = argIn[7];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    double* A_ptr = (double*)A.getDataPointer();
    ArrayOf B = argIn[8];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    double* B_ptr = (double*)B.getDataPointer();
    ArrayOf Q = argIn[9];
    Dimensions dimsQ = Q.getDimensions();
    Q.promoteType(NLS_DOUBLE);
    double* Q_ptr = (double*)Q.getDataPointer();
    ArrayOf R = argIn[10];
    Dimensions dimsR = R.getDimensions();
    R.promoteType(NLS_DOUBLE);
    double* R_ptr = (double*)R.getDataPointer();
    ArrayOf L = argIn[11];
    Dimensions dimsL = L.getDimensions();
    L.promoteType(NLS_DOUBLE);
    double* L_ptr = (double*)L.getDataPointer();
    ArrayOf TOL = argIn[12];
    Dimensions dimsTOL = TOL.getDimensions();
    TOL.promoteType(NLS_DOUBLE);
    double* TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getRows();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDQ = ArrayOf::int32VectorConstructor(1);
    int* LDQ_ptr = (int*)LDQ.getDataPointer();
    LDQ_ptr[0] = std::max(1, std::max((int)A.getRows(), (int)P.getContentAsInteger32Scalar()));
    ArrayOf LDR = ArrayOf::int32VectorConstructor(1);
    int* LDR_ptr = (int*)LDR.getDataPointer();
    LDR_ptr[0] = std::max(1, std::max((int)B.getColumns(), (int)P.getContentAsInteger32Scalar()));
    ArrayOf LDL = ArrayOf::int32VectorConstructor(1);
    int* LDL_ptr = (int*)LDL.getDataPointer();
    LDL_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDX = ArrayOf::int32VectorConstructor(1);
    int* LDX_ptr = (int*)LDX.getDataPointer();
    LDX_ptr[0] = std::max(1, (int)A.getRows());
    ArrayOf LDS = ArrayOf::int32VectorConstructor(1);
    int* LDS_ptr = (int*)LDS.getDataPointer();
    LDS_ptr[0] = (JOBB.getContentAsCString().compare("B") == 0)
        ? std::max(1, 2 * (int)A.getRows() + (int)B.getColumns())
        : std::max(1, 2 * (int)A.getRows());
    ArrayOf LDT = ArrayOf::int32VectorConstructor(1);
    int* LDT_ptr = (int*)LDT.getDataPointer();
    LDT_ptr[0] = (JOBB.getContentAsCString().compare("B") == 0)
        ? std::max(1, 2 * (int)A.getRows() + (int)B.getColumns())
        : (DICO.getContentAsCString().compare("D") == 0) ? std::max(1, 2 * (int)A.getRows())
                                                         : 1;
    ArrayOf LDU = ArrayOf::int32VectorConstructor(1);
    int* LDU_ptr = (int*)LDU.getDataPointer();
    LDU_ptr[0] = std::max(1, 2 * (int)A.getRows());
    ArrayOf IWORK = ArrayOf::int32Matrix2dConstructor(1,
        JOBB.getContentAsCString().compare("B") == 0
            ? std::max(std::max(1, (int)B.getColumns()), 2 * (int)A.getRows())
            : std::max(1, 2 * (int)A.getRows()));
    int* IWORK_ptr = (int*)IWORK.getDataPointer();
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1,
        std::max(std::max(std::max(7 * (2 * (int)A.getRows() + 1) + 16, 16 * (int)A.getRows()),
                     2 * (int)A.getRows() + (int)B.getColumns()),
            3 * (int)B.getColumns()));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0]
        = std::max(std::max(std::max(7 * (2 * (int)A.getRows() + 1) + 16, 16 * (int)A.getRows()),
                       2 * (int)A.getRows() + (int)B.getColumns()),
            3 * (int)B.getColumns());
    ArrayOf BWORK = ArrayOf::int32Matrix2dConstructor(1, 2 * (int)A.getRows());
    int* BWORK_ptr = (int*)BWORK.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf RCOND_output = ArrayOf::doubleVectorConstructor(1);
    double* RCOND_output_ptr = (double*)RCOND_output.getDataPointer();
    ArrayOf X_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, (int)A.getRows()), (indexType)(int)A.getRows());
    double* X_output_ptr = (double*)X_output.getDataPointer();
    ArrayOf ALFAR_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getRows());
    double* ALFAR_output_ptr = (double*)ALFAR_output.getDataPointer();
    ArrayOf ALFAI_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getRows());
    double* ALFAI_output_ptr = (double*)ALFAI_output.getDataPointer();
    ArrayOf BETA_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getRows());
    double* BETA_output_ptr = (double*)BETA_output.getDataPointer();
    ArrayOf S_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)(JOBB.getContentAsCString().compare("B") == 0)
            ? std::max(1, 2 * (int)A.getRows() + (int)B.getColumns())
            : std::max(1, 2 * (int)A.getRows()),
        (indexType)(JOBB.getContentAsCString().compare("B") == 0)
            ? std::max(1, 2 * (int)A.getRows() + (int)B.getColumns())
            : std::max(1, 2 * (int)A.getRows()));
    double* S_output_ptr = (double*)S_output.getDataPointer();
    ArrayOf T_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)(JOBB.getContentAsCString().compare("B") == 0)
            ? std::max(1, 2 * (int)A.getRows() + (int)B.getColumns())
            : (DICO.getContentAsCString().compare("D") == 0) ? std::max(1, 2 * (int)A.getRows())
                                                             : 1,
        (indexType)2 * (int)A.getRows());
    double* T_output_ptr = (double*)T_output.getDataPointer();
    ArrayOf U_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, 2 * (int)A.getRows()), (indexType)2 * (int)A.getRows());
    double* U_output_ptr = (double*)U_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsDICO.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    if (!dimsJOBB.isScalar()) {
        Error(_W("Input argument #2: scalar expected."));
    }
    if (!dimsFACT.isScalar()) {
        Error(_W("Input argument #3: scalar expected."));
    }
    if (!dimsUPLO.isScalar()) {
        Error(_W("Input argument #4: scalar expected."));
    }
    if (!dimsJOBL.isScalar()) {
        Error(_W("Input argument #5: scalar expected."));
    }
    if (!dimsSORT.isScalar()) {
        Error(_W("Input argument #6: scalar expected."));
    }
    if (!dimsP.isScalar()) {
        Error(_W("Input argument #7: scalar expected."));
    }
    if (!dimsTOL.isScalar()) {
        Error(_W("Input argument #13: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try {
        sb02od_(DICO_ptr, JOBB_ptr, FACT_ptr, UPLO_ptr, JOBL_ptr, SORT_ptr, N_ptr, M_ptr, P_ptr,
            A_ptr, LDA_ptr, B_ptr, LDB_ptr, Q_ptr, LDQ_ptr, R_ptr, LDR_ptr, L_ptr, LDL_ptr,
            RCOND_output_ptr, X_output_ptr, LDX_ptr, ALFAR_output_ptr, ALFAI_output_ptr,
            BETA_output_ptr, S_output_ptr, LDS_ptr, T_output_ptr, LDT_ptr, U_output_ptr, LDU_ptr,
            TOL_ptr, IWORK_ptr, DWORK_ptr, LDWORK_ptr, BWORK_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("sb02od function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval << RCOND_output;
    }
    if (nLhs > 1) {
        retval << X_output;
    }
    if (nLhs > 2) {
        retval << ALFAR_output;
    }
    if (nLhs > 3) {
        retval << ALFAI_output;
    }
    if (nLhs > 4) {
        retval << BETA_output;
    }
    if (nLhs > 5) {
        retval << S_output;
    }
    if (nLhs > 6) {
        retval << T_output;
    }
    if (nLhs > 7) {
        retval << U_output;
    }
    if (nLhs > 8) {
        retval << INFO_output;
    }
    return retval;
}
//=============================================================================
