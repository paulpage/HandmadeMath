#include "../HandmadeTest.h"

TEST(Division, Vec2Vec2)
{
    Vec2 v2_1 = V2(1.0f, 3.0f);
    Vec2 v2_2 = V2(2.0f, 4.0f);

    {
        Vec2 result = div_v2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
    }
#ifdef __cplusplus
    {
        Vec2 result = div(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
    }
    {
        Vec2 result = v2_1 / v2_2;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
    }

    v2_1 /= v2_2;
    EXPECT_FLOAT_EQ(v2_1.x, 0.5f);
    EXPECT_FLOAT_EQ(v2_1.y, 0.75f);
#endif
}

TEST(Division, Vec2Scalar)
{
    Vec2 v2 = V2(1.0f, 2.0f);
    float s = 2;

    {
        Vec2 result = div_v2f(v2, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = div(v2, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
    }
    {
        Vec2 result = v2 / s;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
    }

    v2 /= s;
    EXPECT_FLOAT_EQ(v2.x, 0.5f);
    EXPECT_FLOAT_EQ(v2.y, 1.0f);
#endif
}

TEST(Division, Vec3Vec3)
{
    Vec3 v3_1 = V3(1.0f, 3.0f, 5.0f);
    Vec3 v3_2 = V3(2.0f, 4.0f, 0.5f);

    {
        Vec3 result = div_v3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = div(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
    }
    {
        Vec3 result = v3_1 / v3_2;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
    }

    v3_1 /= v3_2;
    EXPECT_FLOAT_EQ(v3_1.x, 0.5f);
    EXPECT_FLOAT_EQ(v3_1.y, 0.75f);
    EXPECT_FLOAT_EQ(v3_1.z, 10.0f);
#endif
}

TEST(Division, Vec3Scalar)
{
    Vec3 v3 = V3(1.0f, 2.0f, 3.0f);
    float s = 2;

    {
        Vec3 result = div_v3f(v3, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
    }
#ifdef __cplusplus
    {
        Vec3 result = div(v3, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
    }
    {
        Vec3 result = v3 / s;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
    }

    v3 /= s;
    EXPECT_FLOAT_EQ(v3.x, 0.5f);
    EXPECT_FLOAT_EQ(v3.y, 1.0f);
    EXPECT_FLOAT_EQ(v3.z, 1.5f);
#endif
}

TEST(Division, Vec4Vec4)
{
    Vec4 v4_1 = V4(1.0f, 3.0f, 5.0f, 1.0f);
    Vec4 v4_2 = V4(2.0f, 4.0f, 0.5f, 4.0f);

    {
        Vec4 result = div_v4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 0.25f);
    }
#ifdef __cplusplus
    {
        Vec4 result = div(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 0.25f);
    }
    {
        Vec4 result = v4_1 / v4_2;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 0.75f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 0.25f);
    }

    v4_1 /= v4_2;
    EXPECT_FLOAT_EQ(v4_1.x, 0.5f);
    EXPECT_FLOAT_EQ(v4_1.y, 0.75f);
    EXPECT_FLOAT_EQ(v4_1.z, 10.0f);
    EXPECT_FLOAT_EQ(v4_1.w, 0.25f);
#endif
}

TEST(Division, Vec4Scalar)
{
    Vec4 v4 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    float s = 2;

    {
        Vec4 result = div_v4f(v4, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = div(v4, s);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }
    {
        Vec4 result = v4 / s;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }

    v4 /= s;
    EXPECT_FLOAT_EQ(v4.x, 0.5f);
    EXPECT_FLOAT_EQ(v4.y, 1.0f);
    EXPECT_FLOAT_EQ(v4.z, 1.5f);
    EXPECT_FLOAT_EQ(v4.w, 2.0f);
#endif
}

TEST(Division, Mat2Scalar) 
{
    Mat2 m = M2();
    float s = 0.5f;

    int Counter = 1;
    for (int Column = 0; Column < 2; ++Column) {
        for (int Row = 0; Row < 2; ++Row) {
            m.elements[Column][Row] = Counter++;
        }
    }

    {
        Mat2 result = div_m2f(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 8.0f);
    }

#ifdef __cplusplus
    {
        Mat2 result = div(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 8.0f);
    }

    {
        Mat2 result = m / s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 8.0f);
    }
#endif
}


TEST(Division, Mat3Scalar) 
{
    Mat3 m = M3();
    float s = 0.5f;

    int Counter = 1;
    for (int Column = 0; Column < 3; ++Column) {
        for (int Row = 0; Row < 3; ++Row) {
            m.elements[Column][Row] = Counter++;
        }
    }

    {
        Mat3 result = div_m3f(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 8.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 14.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 16.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 18.0f);
    }

#ifdef __cplusplus
    {
        Mat3 result = div(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 8.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 14.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 16.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 18.0f);
    }

    {
        Mat3 result = m / s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 8.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 14.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 16.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 18.0f);
    }
#endif
}

TEST(Division, Mat4Scalar)
{
    Mat4 m4 = M4(); // will have 1 - 16
    float s = 2;

    // Fill the matrix
    int Counter = 1;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            m4.elements[Column][Row] = Counter;
            ++Counter;
        }
    }

    // Test the results
    {
        Mat4 result = div_m4f(m4, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 0.5f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 1.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 1.5f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 2.5f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 3.5f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 4.5f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 5.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 5.5f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 6.5f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 7.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 7.5f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 8.0f);
    }
#ifdef __cplusplus
    {
        Mat4 result = div(m4, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 0.5f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 1.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 1.5f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 2.5f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 3.5f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 4.5f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 5.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 5.5f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 6.5f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 7.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 7.5f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 8.0f);
    }
    {
        Mat4 result = m4 / s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 0.5f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 1.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 1.5f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 2.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 2.5f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 3.5f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 4.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 4.5f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 5.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 5.5f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 6.5f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 7.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 7.5f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 8.0f);
    }

    m4 /= s;
    EXPECT_FLOAT_EQ(m4.elements[0][0], 0.5f);
    EXPECT_FLOAT_EQ(m4.elements[0][1], 1.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][2], 1.5f);
    EXPECT_FLOAT_EQ(m4.elements[0][3], 2.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][0], 2.5f);
    EXPECT_FLOAT_EQ(m4.elements[1][1], 3.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][2], 3.5f);
    EXPECT_FLOAT_EQ(m4.elements[1][3], 4.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][0], 4.5f);
    EXPECT_FLOAT_EQ(m4.elements[2][1], 5.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][2], 5.5f);
    EXPECT_FLOAT_EQ(m4.elements[2][3], 6.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][0], 6.5f);
    EXPECT_FLOAT_EQ(m4.elements[3][1], 7.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][2], 7.5f);
    EXPECT_FLOAT_EQ(m4.elements[3][3], 8.0f);
#endif
}

TEST(Division, QuaternionScalar)
{
    Quat q = Q(1.0f, 2.0f, 3.0f, 4.0f);
    float f = 2.0f;

    {
        Quat result = div_qf(q, f);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }
#ifdef __cplusplus
    {
        Quat result = div(q, f);
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }
    {
        Quat result = q / f;
        EXPECT_FLOAT_EQ(result.x, 0.5f);
        EXPECT_FLOAT_EQ(result.y, 1.0f);
        EXPECT_FLOAT_EQ(result.z, 1.5f);
        EXPECT_FLOAT_EQ(result.w, 2.0f);
    }

    q /= f;
    EXPECT_FLOAT_EQ(q.x, 0.5f);
    EXPECT_FLOAT_EQ(q.y, 1.0f);
    EXPECT_FLOAT_EQ(q.z, 1.5f);
    EXPECT_FLOAT_EQ(q.w, 2.0f);
#endif
}
