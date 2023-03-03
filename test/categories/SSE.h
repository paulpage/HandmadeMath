#include "../HandmadeTest.h"

#ifdef HANDMADE_MATH__USE_SSE

TEST(SSE, LinearCombine)
{
    Mat4 MatrixOne = M4D(2.0f);
    Mat4 MatrixTwo = M4D(4.0f);
    Mat4 Result;

    Result.columns[0] = linear_combine_v4m4(MatrixOne.columns[0], MatrixTwo);
    Result.columns[1] = linear_combine_v4m4(MatrixOne.columns[1], MatrixTwo);
    Result.columns[2] = linear_combine_v4m4(MatrixOne.columns[2], MatrixTwo);
    Result.columns[3] = linear_combine_v4m4(MatrixOne.columns[3], MatrixTwo);

    {
        EXPECT_FLOAT_EQ(Result.elements[0][0], 8.0f);
        EXPECT_FLOAT_EQ(Result.elements[0][1], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[0][2], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[0][3], 0.0f);

        EXPECT_FLOAT_EQ(Result.elements[1][0], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[1][1], 8.0f);
        EXPECT_FLOAT_EQ(Result.elements[1][2], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[1][3], 0.0f);

        EXPECT_FLOAT_EQ(Result.elements[2][0], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[2][1], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[2][2], 8.0f);
        EXPECT_FLOAT_EQ(Result.elements[2][3], 0.0f);

        EXPECT_FLOAT_EQ(Result.elements[3][0], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[3][1], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[3][2], 0.0f);
        EXPECT_FLOAT_EQ(Result.elements[3][3], 8.0f);
    }
}

#endif
