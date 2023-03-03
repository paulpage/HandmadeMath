#include "../HandmadeTest.h"

TEST(Subtraction, Vec2)
{
    Vec2 v2_1 = V2(1.0f, 2.0f);
    Vec2 v2_2 = V2(3.0f, 4.0f);

    {
        Vec2 result = sub_v2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, -2.0f);
        EXPECT_FLOAT_EQ(result.y, -2.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = sub(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, -2.0f);
        EXPECT_FLOAT_EQ(result.y, -2.0f);
    }
    {
        Vec2 result = v2_1 - v2_2;
        EXPECT_FLOAT_EQ(result.x, -2.0f);
        EXPECT_FLOAT_EQ(result.y, -2.0f);
    }

    v2_1 -= v2_2;
    EXPECT_FLOAT_EQ(v2_1.x, -2.0f);
    EXPECT_FLOAT_EQ(v2_1.y, -2.0f);
#endif
}

TEST(Subtraction, Vec3)
{
    Vec3 v3_1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v3_2 = V3(4.0f, 5.0f, 6.0f);

    {
        Vec3 result = sub_v3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, -3.0f);
        EXPECT_FLOAT_EQ(result.y, -3.0f);
        EXPECT_FLOAT_EQ(result.z, -3.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = sub(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, -3.0f);
        EXPECT_FLOAT_EQ(result.y, -3.0f);
        EXPECT_FLOAT_EQ(result.z, -3.0f);
    }
    {
        Vec3 result = v3_1 - v3_2;
        EXPECT_FLOAT_EQ(result.x, -3.0f);
        EXPECT_FLOAT_EQ(result.y, -3.0f);
        EXPECT_FLOAT_EQ(result.z, -3.0f);
    }

    v3_1 -= v3_2;
    EXPECT_FLOAT_EQ(v3_1.x, -3.0f);
    EXPECT_FLOAT_EQ(v3_1.y, -3.0f);
    EXPECT_FLOAT_EQ(v3_1.z, -3.0f);
#endif
}

TEST(Subtraction, Vec4)
{
    Vec4 v4_1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4_2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Vec4 result = sub_v4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = sub(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }
    {
        Vec4 result = v4_1 - v4_2;
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }

    v4_1 -= v4_2;
    EXPECT_FLOAT_EQ(v4_1.x, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.y, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.z, -4.0f);
    EXPECT_FLOAT_EQ(v4_1.w, -4.0f);
#endif
}

TEST(Subtraction, Mat2)
{
    Mat2 a = M2();
    Mat2 b = M2();
    
    int Counter = 1;
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            a.elements[Column][Row] = Counter++;
        }
    }
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            b.elements[Column][Row] = Counter++;
        }
    }

    {
        Mat2 result = sub_m2(b,a);
        EXPECT_FLOAT_EQ(result.elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][1], 4.0);
    }
#ifdef __cplusplus
    {
        Mat2 result = sub(b,a);
        EXPECT_FLOAT_EQ(result.elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][1], 4.0);
    }

    {
        Mat2 result = b - a;
        EXPECT_FLOAT_EQ(result.elements[0][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][0], 4.0);
        EXPECT_FLOAT_EQ(result.elements[1][1], 4.0);
    }

    b -= a;
    EXPECT_FLOAT_EQ(b.elements[0][0], 4.0);
    EXPECT_FLOAT_EQ(b.elements[0][1], 4.0);
    EXPECT_FLOAT_EQ(b.elements[1][0], 4.0);
    EXPECT_FLOAT_EQ(b.elements[1][1], 4.0);
#endif
}


TEST(Subtraction, Mat3)
{
    Mat3 a = M3();
    Mat3 b = M3();
    
    int Counter = 1;
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            a.elements[Column][Row] = Counter++;
        }
    }
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            b.elements[Column][Row] = Counter++;
        }
    }

    {
        Mat3 result = sub_m3(b,a);
        EXPECT_FLOAT_EQ(result.elements[0][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[0][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][2], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][2], 9.0);
    }
#ifdef __cplusplus
    {
        Mat3 result = sub(b,a);
        EXPECT_FLOAT_EQ(result.elements[0][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[0][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[1][2], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][0], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][1], 9.0);
        EXPECT_FLOAT_EQ(result.elements[2][2], 9.0);
    }

    b -= a;
    EXPECT_FLOAT_EQ(b.elements[0][0], 9.0);
    EXPECT_FLOAT_EQ(b.elements[0][1], 9.0);
    EXPECT_FLOAT_EQ(b.elements[0][2], 9.0);
    EXPECT_FLOAT_EQ(b.elements[1][0], 9.0);
    EXPECT_FLOAT_EQ(b.elements[1][1], 9.0);
    EXPECT_FLOAT_EQ(b.elements[1][2], 9.0);
    EXPECT_FLOAT_EQ(b.elements[2][0], 9.0);
    EXPECT_FLOAT_EQ(b.elements[2][1], 9.0);
    EXPECT_FLOAT_EQ(b.elements[2][2], 9.0);
#endif
}

TEST(Subtraction, Mat4)
{
    Mat4 m4_1 = M4(); // will have 1 - 16
    Mat4 m4_2 = M4(); // will have 17 - 32

    // Fill the matrices
    int Counter = 1;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4_1.elements[Column][Row] = Counter;
            ++Counter;
        }
    }
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4_2.elements[Column][Row] = Counter;
            ++Counter;
        }
    }

    // Test the results
    {
        Mat4 result = sub_m4(m4_1, m4_2);
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], -16.0f);
            }
        }
    }
#ifdef __cplusplus
    {
        Mat4 result = sub(m4_1, m4_2);
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], -16.0f);
            }
        }
    }
    {
        Mat4 result = m4_1 - m4_2;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], -16.0f);
            }
        }
    }

    m4_1 -= m4_2;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            EXPECT_FLOAT_EQ(m4_1.elements[Column][Row], -16.0f);
        }
    }
#endif
}

TEST(Subtraction, Quaternion)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Quat result = sub_q(q1, q2);
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }
#ifdef __cplusplus
    {
        Quat result = sub(q1, q2);
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }
    {
        Quat result = q1 - q2;
        EXPECT_FLOAT_EQ(result.x, -4.0f);
        EXPECT_FLOAT_EQ(result.y, -4.0f);
        EXPECT_FLOAT_EQ(result.z, -4.0f);
        EXPECT_FLOAT_EQ(result.w, -4.0f);
    }

    q1 -= q2;
    EXPECT_FLOAT_EQ(q1.x, -4.0f);
    EXPECT_FLOAT_EQ(q1.y, -4.0f);
    EXPECT_FLOAT_EQ(q1.z, -4.0f);
    EXPECT_FLOAT_EQ(q1.w, -4.0f);
#endif
}

#ifdef __cplusplus
TEST(UnaryMinus, Vec2)
{
    Vec2 VectorOne = {1.0f, 2.0f};
    Vec2 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.x, -1.0f);
    EXPECT_FLOAT_EQ(Result.y, -2.0f);
}

TEST(UnaryMinus, Vec3)
{
    Vec3 VectorOne = {1.0f, 2.0f, 3.0f};
    Vec3 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.x, -1.0f);
    EXPECT_FLOAT_EQ(Result.y, -2.0f);
    EXPECT_FLOAT_EQ(Result.z, -3.0f);
}

TEST(UnaryMinus, Vec4)
{
    Vec4 VectorOne = {1.0f, 2.0f, 3.0f, 4.0f};
    Vec4 Result = -VectorOne;
    EXPECT_FLOAT_EQ(Result.x, -1.0f);
    EXPECT_FLOAT_EQ(Result.y, -2.0f);
    EXPECT_FLOAT_EQ(Result.z, -3.0f);
    EXPECT_FLOAT_EQ(Result.w, -4.0f);
}
#endif
