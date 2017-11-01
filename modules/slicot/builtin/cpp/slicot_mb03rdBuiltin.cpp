//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "Error.hpp"
#include "slicot_mb03rdBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
extern int mb03rd_ ( const char *JOBX, const char *SORT, int *N, double *PMAX, double *A, int *LDA, double *X, int *LDX, int *NBLCKS, double *BLSIZE, double *WR, double *WI, double *TOL, double *DWORK, int *INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, X_OUT, NBLCKS, BLSIZE, WR, WI, INFO] = slicot_mb03rd(JOBX, SORT, PMAX, A_IN, X_IN, TOL)
//=============================================================================
ArrayOfVector Nelson::SlicotGateway::slicot_mb03rdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 7)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 6)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf JOBX = argIn[0];
    Dimensions dimsJOBX = JOBX.getDimensions();
    std::string JOBX_string = JOBX.getContentAsCString();
    const char* JOBX_ptr = JOBX_string.c_str();
    ArrayOf SORT = argIn[1];
    Dimensions dimsSORT = SORT.getDimensions();
    std::string SORT_string = SORT.getContentAsCString();
    const char* SORT_ptr = SORT_string.c_str();
    ArrayOf PMAX = argIn[2];
    Dimensions dimsPMAX = PMAX.getDimensions();
    PMAX.promoteType(NLS_DOUBLE);
    double *PMAX_ptr = (double*)PMAX.getDataPointer();
    ArrayOf TOL = argIn[5];
    Dimensions dimsTOL = TOL.getDimensions();
    TOL.promoteType(NLS_DOUBLE);
    double *TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[3];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double *A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf X = argIn[4];
    Dimensions dimsX = X.getDimensions();
    X.promoteType(NLS_DOUBLE);
    ArrayOf X_output = X;
    X_output.ensureSingleOwner();
    double *X_output_ptr = (double*)X_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getDimensions().getColumns());
    ArrayOf LDX = ArrayOf::int32VectorConstructor(1);
    int* LDX_ptr = (int*)LDX.getDataPointer();
    LDX_ptr[0] = std::max(1, (int)A.getDimensions().getColumns());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(1 , (int)A.getDimensions().getColumns());
    double * DWORK_ptr = (double*)DWORK.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf NBLCKS_output = ArrayOf::int32VectorConstructor(1);
    int *NBLCKS_output_ptr = (int*)NBLCKS_output.getDataPointer();
    ArrayOf BLSIZE_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getDimensions().getColumns());
    double *BLSIZE_output_ptr = (double*)BLSIZE_output.getDataPointer();
    ArrayOf WR_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getDimensions().getColumns());
    double *WR_output_ptr = (double*)WR_output.getDataPointer();
    ArrayOf WI_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getDimensions().getColumns());
    double *WI_output_ptr = (double*)WI_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int *INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsJOBX.isScalar())
    {
        Error(eval, _W("Input argument #1: scalar expected."));
    }
    if (!dimsSORT.isScalar())
    {
        Error(eval, _W("Input argument #2: scalar expected."));
    }
    if (!dimsPMAX.isScalar())
    {
        Error(eval, _W("Input argument #3: scalar expected."));
    }
    Dimensions dimsA_expected(std::max(1, (int)A.getDimensions().getColumns()), (int)A.getDimensions().getColumns());
    if (!dimsA.equals(dimsA_expected))
    {
        Error(eval, _("Input argument #4: wrong size.") + " " + dimsA_expected.toString() + " " + "expected" + ".");
    }
    Dimensions dimsX_expected(std::max(1, (int)A.getDimensions().getColumns()), (int)A.getDimensions().getColumns());
    if (!dimsX.equals(dimsX_expected))
    {
        Error(eval, _("Input argument #5: wrong size.") + " " + dimsX_expected.toString() + " " + "expected" + ".");
    }
    if (!dimsTOL.isScalar())
    {
        Error(eval, _W("Input argument #6: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try
    {
        mb03rd_ ( JOBX_ptr, SORT_ptr, N_ptr, PMAX_ptr, A_output_ptr, LDA_ptr, X_output_ptr, LDX_ptr, NBLCKS_output_ptr, BLSIZE_output_ptr, WR_output_ptr, WI_output_ptr, TOL_ptr, DWORK_ptr, INFO_output_ptr);
    }
    catch (std::runtime_error &e)
    {
        e.what();
        Error(eval, "mb03rd function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0)
    {
        retval.push_back(A_output);
    }
    if (nLhs > 1)
    {
        retval.push_back(X_output);
    }
    if (nLhs > 2)
    {
        retval.push_back(NBLCKS_output);
    }
    if (nLhs > 3)
    {
        retval.push_back(BLSIZE_output);
    }
    if (nLhs > 4)
    {
        retval.push_back(WR_output);
    }
    if (nLhs > 5)
    {
        retval.push_back(WI_output);
    }
    if (nLhs > 6)
    {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================