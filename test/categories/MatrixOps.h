#include "../HandmadeTest.h"

TEST(InvMatrix, Transpose)
{
    {
        Mat2 Matrix = {
            1.0f, 3.0f,
            2.0f, 4.0f,
        };
        Mat2 Expect = {
            1.0f, 2.0f,
            3.0f, 4.0f,
        };

        {
            Mat2 result = transpose_m2(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
        }
#ifdef __cplusplus
        {
            Mat2 result = transpose(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
        }
#endif
    }

    {
        Mat3 Matrix = {
            1.0f, 4.0f, 7.0f,
            2.0f, 5.0f, 8.0f,
            3.0f, 6.0f, 9.0f,
        };
        Mat3 Expect = {
            1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            7.0f, 8.0f, 9.0f
        };

        {
            Mat3 result = transpose_m3(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[0][2], Expect.elements[0][2]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
            EXPECT_FLOAT_EQ(result.elements[1][2], Expect.elements[1][2]);
            EXPECT_FLOAT_EQ(result.elements[2][0], Expect.elements[2][0]);
            EXPECT_FLOAT_EQ(result.elements[2][1], Expect.elements[2][1]);
            EXPECT_FLOAT_EQ(result.elements[2][2], Expect.elements[2][2]);
        }
#ifdef __cplusplus
        {
            Mat3 result = transpose(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[0][2], Expect.elements[0][2]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
            EXPECT_FLOAT_EQ(result.elements[1][2], Expect.elements[1][2]);
            EXPECT_FLOAT_EQ(result.elements[2][0], Expect.elements[2][0]);
            EXPECT_FLOAT_EQ(result.elements[2][1], Expect.elements[2][1]);
            EXPECT_FLOAT_EQ(result.elements[2][2], Expect.elements[2][2]);
        }
#endif
    }
    {
        Mat4 Matrix = {
            1.0f, 5.0f,  9.0f, 13.0f,
            2.0f, 6.0f, 10.0f, 14.0f, 
            3.0f, 7.0f, 11.0f, 15.0f,
            4.0f, 8.0f, 12.0f, 16.0f
        };
        Mat4 Expect = {
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f,
        };
        {
            Mat4 result = transpose_m4(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[0][2], Expect.elements[0][2]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
            EXPECT_FLOAT_EQ(result.elements[1][2], Expect.elements[1][2]);
            EXPECT_FLOAT_EQ(result.elements[2][0], Expect.elements[2][0]);
            EXPECT_FLOAT_EQ(result.elements[2][1], Expect.elements[2][1]);
            EXPECT_FLOAT_EQ(result.elements[2][2], Expect.elements[2][2]);
        }
#ifdef __cplusplus
        {
            Mat4 result = transpose(Matrix);
            EXPECT_FLOAT_EQ(result.elements[0][0], Expect.elements[0][0]);
            EXPECT_FLOAT_EQ(result.elements[0][1], Expect.elements[0][1]);
            EXPECT_FLOAT_EQ(result.elements[0][2], Expect.elements[0][2]);
            EXPECT_FLOAT_EQ(result.elements[1][0], Expect.elements[1][0]);
            EXPECT_FLOAT_EQ(result.elements[1][1], Expect.elements[1][1]);
            EXPECT_FLOAT_EQ(result.elements[1][2], Expect.elements[1][2]);
            EXPECT_FLOAT_EQ(result.elements[2][0], Expect.elements[2][0]);
            EXPECT_FLOAT_EQ(result.elements[2][1], Expect.elements[2][1]);
            EXPECT_FLOAT_EQ(result.elements[2][2], Expect.elements[2][2]);
        }
#endif
    }

}

TEST(InvMatrix, InvGeneral)
{
    {
        Mat4 Matrix = {
            12.0f, 2.0f, 1.0f, 1.0f,
            0.0f, 0.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 5.0f, 1.0f,
            11.0f, 1.0f, 0.0f, 10.0f
        };

        Mat4 Expect = M4D(1.0);
        Mat4 Inverse = invgeneral_m4(Matrix);
        Mat4 Result = mul_m4(Matrix, Inverse);
        
        float Det = determinant_m4(Matrix);
        EXPECT_FLOAT_EQ(Det, -80.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[0][2], Expect.elements[0][2]);
        EXPECT_FLOAT_EQ(Result.elements[0][3], Expect.elements[0][3]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][2], Expect.elements[1][2]);
        EXPECT_FLOAT_EQ(Result.elements[1][3], Expect.elements[1][3]);
        EXPECT_FLOAT_EQ(Result.elements[2][0], Expect.elements[2][0]);
        EXPECT_FLOAT_EQ(Result.elements[2][1], Expect.elements[2][1]);
        EXPECT_FLOAT_EQ(Result.elements[2][2], Expect.elements[2][2]);
        EXPECT_FLOAT_EQ(Result.elements[2][3], Expect.elements[2][3]);
        EXPECT_FLOAT_EQ(Result.elements[3][0], Expect.elements[3][0]);
        EXPECT_FLOAT_EQ(Result.elements[3][1], Expect.elements[3][1]);
        EXPECT_FLOAT_EQ(Result.elements[3][2], Expect.elements[3][2]);
        EXPECT_FLOAT_EQ(Result.elements[3][3], Expect.elements[3][3]);

#ifdef __cplusplus
        Inverse = invgeneral(Matrix);
        Result = mul(Matrix, Inverse);
        
        Det = determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, -80.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[0][2], Expect.elements[0][2]);
        EXPECT_FLOAT_EQ(Result.elements[0][3], Expect.elements[0][3]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][2], Expect.elements[1][2]);
        EXPECT_FLOAT_EQ(Result.elements[1][3], Expect.elements[1][3]);
        EXPECT_FLOAT_EQ(Result.elements[2][0], Expect.elements[2][0]);
        EXPECT_FLOAT_EQ(Result.elements[2][1], Expect.elements[2][1]);
        EXPECT_FLOAT_EQ(Result.elements[2][2], Expect.elements[2][2]);
        EXPECT_FLOAT_EQ(Result.elements[2][3], Expect.elements[2][3]);
        EXPECT_FLOAT_EQ(Result.elements[3][0], Expect.elements[3][0]);
        EXPECT_FLOAT_EQ(Result.elements[3][1], Expect.elements[3][1]);
        EXPECT_FLOAT_EQ(Result.elements[3][2], Expect.elements[3][2]);
        EXPECT_FLOAT_EQ(Result.elements[3][3], Expect.elements[3][3]);
#endif
    }

    {
        Mat3 Matrix = {
            12.0f, 2.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 5.0f
        };

        Mat3 Expect = M3D(1.0);
        Mat3 Inverse = invgeneral_m3(Matrix);
        Mat3 Result = mul_m3(Matrix, Inverse);
        
        float Det = determinant_m3(Matrix);
        EXPECT_FLOAT_EQ(Det, -12.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[0][2], Expect.elements[0][2]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][2], Expect.elements[1][2]);
        EXPECT_FLOAT_EQ(Result.elements[2][0], Expect.elements[2][0]);
        EXPECT_FLOAT_EQ(Result.elements[2][1], Expect.elements[2][1]);
        EXPECT_FLOAT_EQ(Result.elements[2][2], Expect.elements[2][2]);

#ifdef __cplusplus
        Inverse = invgeneral(Matrix);
        Result = mul(Matrix, Inverse);
        Det = determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, -12.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[0][2], Expect.elements[0][2]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][2], Expect.elements[1][2]);
        EXPECT_FLOAT_EQ(Result.elements[2][0], Expect.elements[2][0]);
        EXPECT_FLOAT_EQ(Result.elements[2][1], Expect.elements[2][1]);
        EXPECT_FLOAT_EQ(Result.elements[2][2], Expect.elements[2][2]);
#endif
    }

    {
        Mat2 Matrix = {
            12.0f, 2.0f, 
             1.0f, 5.0f
        };

        Mat2 Expect = M2D(1.0);
        Mat2 Inverse = invgeneral_m2(Matrix);
        Mat2 Result = mul_m2(Matrix, Inverse);
        
        float Det = determinant_m2(Matrix);
        EXPECT_FLOAT_EQ(Det, 58.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);

#ifdef __cplusplus
        Inverse = invgeneral(Matrix);
        Result = mul(Matrix, Inverse);
        Det = determinant(Matrix);
        EXPECT_FLOAT_EQ(Det, 58.0f);

        EXPECT_FLOAT_EQ(Result.elements[0][0], Expect.elements[0][0]);
        EXPECT_FLOAT_EQ(Result.elements[0][1], Expect.elements[0][1]);
        EXPECT_FLOAT_EQ(Result.elements[1][0], Expect.elements[1][0]);
        EXPECT_FLOAT_EQ(Result.elements[1][1], Expect.elements[1][1]);
#endif
    }    
}

TEST(InvMatrix, InvOrthographic)
{
    {
        Mat4 Matrix = orthographic_rh_no(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = inv_orthographic(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = orthographic_rh_zo(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = inv_orthographic(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = orthographic_lh_no(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = inv_orthographic(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = orthographic_lh_zo(-160+100, 160+100, -90+200, 90+200, 10, 10000);
        Mat4 Inverse = inv_orthographic(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
}

TEST(InvMatrix, InvPerspective)
{
    {
        Mat4 Matrix = perspective_rh_no(angle_deg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = inv_perspective_rh(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = perspective_rh_zo(angle_deg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = inv_perspective_rh(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = perspective_lh_no(angle_deg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = inv_perspective_lh(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
    {
        Mat4 Matrix = perspective_lh_zo(angle_deg(120), 16.0/9.0, 10, 10000);
        Mat4 Inverse = inv_perspective_lh(Matrix);
        EXPECT_M4_EQ(mul_m4(Matrix, Inverse), M4D(1.0f));
    }
}

TEST(InvMatrix, InvLookAt)
{
    {
        Vec3 Eye = {10.0f, 10.0f, 10.0f};
        Vec3 Center = {100.0f, 200.0f, 30.0f};
        Vec3 Up = {0.0f, 0.0f, 1.0f};
        Mat4 Matrix = look_at_rh(Eye, Center, Up);
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = inv_look_at(Matrix);
        Mat4 Result = mul_m4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
    {
        Vec3 Eye = {10.0f, 10.0f, 10.0f};
        Vec3 Center = {100.0f, 200.0f, 30.0f};
        Vec3 Up = {0.0f, 0.0f, 1.0f};
        Mat4 Matrix = look_at_lh(Eye, Center, Up);
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = inv_look_at(Matrix);
        Mat4 Result = mul_m4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
}

TEST(InvMatrix, InvRotate)
{
    {
        Vec3 Axis = {1.0f, -1.0f, 0.5f};
        Mat4 Matrix = rotate_rh(angle_deg(30), norm_v3(Axis));
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = inv_rotate(Matrix);
        Mat4 Result = mul_m4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
    {
        Vec3 Axis = {1.0f, -1.0f, 0.5f};
        Mat4 Matrix = rotate_lh(angle_deg(30), norm_v3(Axis));
        Mat4 Expect = M4D(1.0f);
        Mat4 Inverse = inv_rotate(Matrix);
        Mat4 Result = mul_m4(Matrix, Inverse);
        EXPECT_M4_NEAR(Result, Expect, 0.001f);
    }
}

TEST(InvMatrix, InvScale)
{
    Vec3 Scale  = {1.0f, -1.0f, 0.5f};
    Mat4 Matrix = scale(Scale);
    Mat4 Expect = M4D(1.0f);
    Mat4 Inverse = inv_scale(Matrix);
    Mat4 Result = mul_m4(Matrix, Inverse);
    EXPECT_M4_EQ(Result, Expect);
}

TEST(InvMatrix, InvTranslate)
{
    Vec3 Move  = {1.0f, -1.0f, 0.5f};
    Mat4 Matrix = translate(Move);
    Mat4 Expect = M4D(1.0f);
    Mat4 Inverse = inv_translate(Matrix);
    Mat4 Result = mul_m4(Matrix, Inverse);
    EXPECT_M4_EQ(Result, Expect);
}
