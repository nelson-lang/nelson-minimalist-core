//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "slicot_ab08ndBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    ab08nd_(const char* EQUIL, int* N, int* M, int* P, const double* A, int* LDA, const double* B,
        int* LDB, const double* C, int* LDC, const double* D, int* LDD, int* NU, int* RANK,
        int* DINFZ, int* NKROR, int* NKROL, int* INFZ, int* KRONR, int* KRONL, double* AF,
        int* LDAF, double* BF, int* LDBF, double* TOL, int* IWORK, double* DWORK, int* LDWORK,
        int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [NU, RANK, DINFZ, NKROR, NKROL, INFZ, KRONR, KRONL, AF, BF, INFO] = slicot_ab08nd(EQUIL, N, M, P,
// A, B, C, D, TOL)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_ab08ndBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 11) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 9) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf EQUIL = argIn[0];
    Dimensions dimsEQUIL = EQUIL.getDimensions();
    std::string EQUIL_string = EQUIL.getContentAsCString();
    const char* EQUIL_ptr = EQUIL_string.c_str();
    ArrayOf N = argIn[1];
    Dimensions dimsN = N.getDimensions();
    N.promoteType(NLS_INT32);
    int* N_ptr = (int*)N.getDataPointer();
    ArrayOf M = argIn[2];
    Dimensions dimsM = M.getDimensions();
    M.promoteType(NLS_INT32);
    int* M_ptr = (int*)M.getDataPointer();
    ArrayOf P = argIn[3];
    Dimensions dimsP = P.getDimensions();
    P.promoteType(NLS_INT32);
    int* P_ptr = (int*)P.getDataPointer();
    ArrayOf A = argIn[4];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    double* A_ptr = (double*)A.getDataPointer();
    ArrayOf B = argIn[5];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    double* B_ptr = (double*)B.getDataPointer();
    ArrayOf C = argIn[6];
    Dimensions dimsC = C.getDimensions();
    C.promoteType(NLS_DOUBLE);
    double* C_ptr = (double*)C.getDataPointer();
    ArrayOf D = argIn[7];
    Dimensions dimsD = D.getDimensions();
    D.promoteType(NLS_DOUBLE);
    double* D_ptr = (double*)D.getDataPointer();
    ArrayOf TOL = argIn[8];
    Dimensions dimsTOL = TOL.getDimensions();
    TOL.promoteType(NLS_DOUBLE);
    double* TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    // LOCAL VARIABLES
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, N.getContentAsInteger32Scalar());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = (int)std::max(1, N.getContentAsInteger32Scalar());
    ArrayOf LDC = ArrayOf::int32VectorConstructor(1);
    int* LDC_ptr = (int*)LDC.getDataPointer();
    LDC_ptr[0] = std::max(1, P.getContentAsInteger32Scalar());
    ArrayOf LDD = ArrayOf::int32VectorConstructor(1);
    int* LDD_ptr = (int*)LDD.getDataPointer();
    LDD_ptr[0] = std::max(1, P.getContentAsInteger32Scalar());
    ArrayOf LDAF = ArrayOf::int32VectorConstructor(1);
    int* LDAF_ptr = (int*)LDAF.getDataPointer();
    LDAF_ptr[0] = std::max(1, N.getContentAsInteger32Scalar() + M.getContentAsInteger32Scalar());
    ArrayOf LDBF = ArrayOf::int32VectorConstructor(1);
    int* LDBF_ptr = (int*)LDBF.getDataPointer();
    LDBF_ptr[0] = std::max(1, N.getContentAsInteger32Scalar() + P.getContentAsInteger32Scalar());
    ArrayOf IWORK = ArrayOf::int32Matrix2dConstructor(
        1, std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar()));
    int* IWORK_ptr = (int*)IWORK.getDataPointer();
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1,
        std::max(std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar()),
            N.getContentAsInteger32Scalar())
            + std::max(
                  3 * std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar())
                      - 1,
                  N.getContentAsInteger32Scalar()
                      + std::max(
                            N.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar())));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0]
        = std::max(std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar()),
              N.getContentAsInteger32Scalar())
        + std::max(
              3 * std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar()) - 1,
              N.getContentAsInteger32Scalar()
                  + std::max(M.getContentAsInteger32Scalar(), P.getContentAsInteger32Scalar()));
    // OUTPUT VARIABLES
    ArrayOf NU_output = ArrayOf::int32VectorConstructor(1);
    int* NU_output_ptr = (int*)NU_output.getDataPointer();
    ArrayOf RANK_output = ArrayOf::int32VectorConstructor(1);
    int* RANK_output_ptr = (int*)RANK_output.getDataPointer();
    ArrayOf DINFZ_output = ArrayOf::int32VectorConstructor(1);
    int* DINFZ_output_ptr = (int*)DINFZ_output.getDataPointer();
    ArrayOf NKROR_output = ArrayOf::int32VectorConstructor(1);
    int* NKROR_output_ptr = (int*)NKROR_output.getDataPointer();
    ArrayOf NKROL_output = ArrayOf::int32VectorConstructor(1);
    int* NKROL_output_ptr = (int*)NKROL_output.getDataPointer();
    ArrayOf INFZ_output = ArrayOf::int32Matrix2dConstructor(
        (indexType)1, (indexType)N.getContentAsInteger32Scalar());
    int* INFZ_output_ptr = (int*)INFZ_output.getDataPointer();
    ArrayOf KRONR_output = ArrayOf::int32Matrix2dConstructor((indexType)1,
        (indexType)std::max(N.getContentAsInteger32Scalar(), M.getContentAsInteger32Scalar()) + 1);
    int* KRONR_output_ptr = (int*)KRONR_output.getDataPointer();
    ArrayOf KRONL_output = ArrayOf::int32Matrix2dConstructor((indexType)1,
        (indexType)std::max(N.getContentAsInteger32Scalar(), M.getContentAsInteger32Scalar()) + 1);
    int* KRONL_output_ptr = (int*)KRONL_output.getDataPointer();
    ArrayOf AF_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)std::max(1, N.getContentAsInteger32Scalar() + M.getContentAsInteger32Scalar()),
        (indexType)N.getContentAsInteger32Scalar()
            + std::min(P.getContentAsInteger32Scalar(), M.getContentAsInteger32Scalar()));
    double* AF_output_ptr = (double*)AF_output.getDataPointer();
    ArrayOf BF_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)N.getContentAsInteger32Scalar() + M.getContentAsInteger32Scalar(),
        (indexType)std::max(1, N.getContentAsInteger32Scalar() + P.getContentAsInteger32Scalar()));
    double* BF_output_ptr = (double*)BF_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsEQUIL.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    if (!dimsN.isScalar()) {
        Error(_W("Input argument #2: scalar expected."));
    }
    if (!dimsM.isScalar()) {
        Error(_W("Input argument #3: scalar expected."));
    }
    if (!dimsP.isScalar()) {
        Error(_W("Input argument #4: scalar expected."));
    }
    Dimensions dimsA_expected(
        (int)std::max(1, N.getContentAsInteger32Scalar()), (int)N.getContentAsInteger32Scalar());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #5: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    if (!dimsTOL.isScalar()) {
        Error(_W("Input argument #9: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try {
        ab08nd_(EQUIL_ptr, N_ptr, M_ptr, P_ptr, A_ptr, LDA_ptr, B_ptr, LDB_ptr, C_ptr, LDC_ptr,
            D_ptr, LDD_ptr, NU_output_ptr, RANK_output_ptr, DINFZ_output_ptr, NKROR_output_ptr,
            NKROL_output_ptr, INFZ_output_ptr, KRONR_output_ptr, KRONL_output_ptr, AF_output_ptr,
            LDAF_ptr, BF_output_ptr, LDBF_ptr, TOL_ptr, IWORK_ptr, DWORK_ptr, LDWORK_ptr,
            INFO_output_ptr);
    } catch (const std::runtime_error& e) {
        e.what();
        Error("ab08nd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval.push_back(NU_output);
    }
    if (nLhs > 1) {
        retval.push_back(RANK_output);
    }
    if (nLhs > 2) {
        retval.push_back(DINFZ_output);
    }
    if (nLhs > 3) {
        retval.push_back(NKROR_output);
    }
    if (nLhs > 4) {
        retval.push_back(NKROL_output);
    }
    if (nLhs > 5) {
        retval.push_back(INFZ_output);
    }
    if (nLhs > 6) {
        retval.push_back(KRONR_output);
    }
    if (nLhs > 7) {
        retval.push_back(KRONL_output);
    }
    if (nLhs > 8) {
        retval.push_back(AF_output);
    }
    if (nLhs > 9) {
        retval.push_back(BF_output);
    }
    if (nLhs > 10) {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
