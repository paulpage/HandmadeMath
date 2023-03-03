#include "../HandmadeTest.h"

TEST(Multiplication, Vec2Vec2)
{
    Vec2 v2_1 = V2(1.0f, 2.0f);
    Vec2 v2_2 = V2(3.0f, 4.0f);

    {
        Vec2 result = mul_v2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = mul(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
    }
    {
        Vec2 result = v2_1 * v2_2;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
    }

    v2_1 *= v2_2;
    EXPECT_FLOAT_EQ(v2_1.x, 3.0f);
    EXPECT_FLOAT_EQ(v2_1.y, 8.0f);
#endif
}

TEST(Multiplication, Vec2Scalar)
{
    Vec2 v2 = V2(1.0f, 2.0f);
    float s = 3.0f;

    {
        Vec2 result = mul_v2f(v2, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = mul(v2, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }
    {
        Vec2 result = v2 * s;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }
    {
        Vec2 result = s * v2;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }

    v2 *= s;
    EXPECT_FLOAT_EQ(v2.x, 3.0f);
    EXPECT_FLOAT_EQ(v2.y, 6.0f);
#endif
}

TEST(Multiplication, Vec3Vec3)
{
    Vec3 v3_1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v3_2 = V3(4.0f, 5.0f, 6.0f);

    {
        Vec3 result = mul_v3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 10.0f);
        EXPECT_FLOAT_EQ(result.z, 18.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = mul(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 10.0f);
        EXPECT_FLOAT_EQ(result.z, 18.0f);
    }
    {
        Vec3 result = v3_1 * v3_2;
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 10.0f);
        EXPECT_FLOAT_EQ(result.z, 18.0f);
    }

    v3_1 *= v3_2;
    EXPECT_FLOAT_EQ(v3_1.x, 4.0f);
    EXPECT_FLOAT_EQ(v3_1.y, 10.0f);
    EXPECT_FLOAT_EQ(v3_1.z, 18.0f);
#endif
}

TEST(Multiplication, Vec3Scalar)
{
    Vec3 v3 = V3(1.0f, 2.0f, 3.0f);
    float s = 3.0f;

    {
        Vec3 result = mul_v3f(v3, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = mul(v3, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }
    {
        Vec3 result = v3 * s;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }
    {
        Vec3 result = s * v3;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }

    v3 *= s;
    EXPECT_FLOAT_EQ(v3.x, 3.0f);
    EXPECT_FLOAT_EQ(v3.y, 6.0f);
    EXPECT_FLOAT_EQ(v3.z, 9.0f);
#endif
}

TEST(Multiplication, Vec4Vec4)
{
    Vec4 v4_1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4_2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Vec4 result = mul_v4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 12.0f);
        EXPECT_FLOAT_EQ(result.z, 21.0f);
        EXPECT_FLOAT_EQ(result.w, 32.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = mul(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 12.0f);
        EXPECT_FLOAT_EQ(result.z, 21.0f);
        EXPECT_FLOAT_EQ(result.w, 32.0f);
    }
    {
        Vec4 result = v4_1 * v4_2;
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 12.0f);
        EXPECT_FLOAT_EQ(result.z, 21.0f);
        EXPECT_FLOAT_EQ(result.w, 32.0f);
    }

    v4_1 *= v4_2;
    EXPECT_FLOAT_EQ(v4_1.x, 5.0f);
    EXPECT_FLOAT_EQ(v4_1.y, 12.0f);
    EXPECT_FLOAT_EQ(v4_1.z, 21.0f);
    EXPECT_FLOAT_EQ(v4_1.w, 32.0f);
#endif
}

TEST(Multiplication, Vec4Scalar)
{
    Vec4 v4 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    float s = 3.0f;

    {
        Vec4 result = mul_v4f(v4, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = mul(v4, s);
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
    {
        Vec4 result = v4 * s;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
    {
        Vec4 result = s * v4;
        EXPECT_FLOAT_EQ(result.x, 3.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }

    v4 *= s;
    EXPECT_FLOAT_EQ(v4.x, 3.0f);
    EXPECT_FLOAT_EQ(v4.y, 6.0f);
    EXPECT_FLOAT_EQ(v4.z, 9.0f);
#endif
}

TEST(Multiplication, Mat2Mat2) {
    Mat2 a = M2();
    Mat2 b = M2();

    int counter = 1;
    for (int Column = 0; Column < 2; Column++) {
        for (int Row = 0; Row < 2; Row++) {
            a.elements[Column][Row] = counter++;
        }
    }
    
    for (int Column = 0; Column < 2; Column++) {
        for (int Row = 0; Row < 2; Row++) {
            b.elements[Column][Row] = counter++;
        }
    }

    {
        Mat2 result = mul_m2(a,b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 34.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 31.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 46.0f);        
    }

#ifdef __cplusplus
    {
        Mat2 result = mul(a,b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 34.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 31.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 46.0f);        
    }

    {
        Mat2 result = a * b;
        EXPECT_FLOAT_EQ(result.elements[0][0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 34.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 31.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 46.0f);        
    }
#endif
}

TEST(Multiplication, Mat2Scalar) {
    Mat2 m = M2();
    float s = 10.0f;

    int counter = 1;
    for (int Column = 0; Column < 2; Column++) {
        for (int Row = 0; Row < 2; Row++) {
            m.elements[Column][Row] = counter++;
        }
    }

    {
        Mat2 result = mul_m2f(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 40.0f);
    }
#ifdef __cplusplus
    {
        Mat2 result = mul(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 40.0f);
    }
    {
        Mat2 result = m * s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 40.0f);
    }
    {
        Mat2 result = s * m;
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 40.0f);
    }
    m *= s;
    EXPECT_FLOAT_EQ(m.elements[0][0], 10.0f);
    EXPECT_FLOAT_EQ(m.elements[0][1], 20.0f);
    EXPECT_FLOAT_EQ(m.elements[1][0], 30.0f);
    EXPECT_FLOAT_EQ(m.elements[1][1], 40.0f);
#endif
}

TEST(Multiplication, Mat2Vec2) {
    Mat2 m = M2();
    Vec2 v = V2(0.0f, 0.0f);

    int counter = 1;
    for (int Column = 0; Column < 2; Column++) {
        for (int Row = 0; Row < 2; Row++) {
            m.elements[Column][Row] = counter++;
        }
    }

    for (int Row = 0; Row < 2; Row++) {
        v.elements[Row] = counter++;
    }

    {
        Vec2 result = mul_m2v2(m, v);
        EXPECT_FLOAT_EQ(result.elements[0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 34.0f);
    }

#ifdef __cplusplus
    {
        Vec2 result = mul(m, v);
        EXPECT_FLOAT_EQ(result.elements[0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 34.0f);
    }
    
    {
        Vec2 result = m * v;
        EXPECT_FLOAT_EQ(result.elements[0], 23.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 34.0f);
    }
#endif
}
 
TEST(Multiplication, Mat3Mat3) 
{
    Mat3 a = M3();
    Mat3 b = M3();

    int counter = 1;
    for (int Column = 0; Column < 3; Column++) {
        for (int Row = 0; Row < 3; Row++) {
            a.elements[Column][Row] = counter++;
        }
    }
    
    for (int Column = 0; Column < 3; Column++) {
        for (int Row = 0; Row < 3; Row++) {
            b.elements[Column][Row] = counter++;
        }
    }

    {
        Mat3 result = mul_m3(a,b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 204.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 174.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 216.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 258.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 210.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 261.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 312.0f);
    }

#ifdef __cplusplus
    {
        Mat3 result = mul(a,b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 204.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 174.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 216.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 258.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 210.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 261.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 312.0f);
    }

    {
        Mat3 result = a * b;
        EXPECT_FLOAT_EQ(result.elements[0][0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 204.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 174.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 216.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 258.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 210.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 261.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 312.0f);
    }
#endif
}

TEST(Multiplication, Mat3Scalar) {
    Mat3 m = M3();
    float s = 10.0f;

    int counter = 1;
    for (int Column = 0; Column < 3; Column++) {
        for (int Row = 0; Row < 3; Row++) {
            m.elements[Column][Row] = counter++;
        }
    }

    {
        Mat3 result = mul_m3f(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 40.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 50.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 60.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 70.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 80.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 90.0f);
    }
#ifdef __cplusplus
    {
        Mat3 result = mul(m, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 40.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 50.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 60.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 70.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 80.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 90.0f);
    }
    {
        Mat3 result = m * s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 40.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 50.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 60.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 70.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 80.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 90.0f);
    }
    {
        Mat3 result = s * m;
        EXPECT_FLOAT_EQ(result.elements[0][0], 10.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 20.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 40.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 50.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 60.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 70.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 80.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 90.0f);
    }
    m *= s;
    EXPECT_FLOAT_EQ(m.elements[0][0], 10.0f);
    EXPECT_FLOAT_EQ(m.elements[0][1], 20.0f);
    EXPECT_FLOAT_EQ(m.elements[0][2], 30.0f);
    EXPECT_FLOAT_EQ(m.elements[1][0], 40.0f);
    EXPECT_FLOAT_EQ(m.elements[1][1], 50.0f);
    EXPECT_FLOAT_EQ(m.elements[1][2], 60.0f);
    EXPECT_FLOAT_EQ(m.elements[2][0], 70.0f);
    EXPECT_FLOAT_EQ(m.elements[2][1], 80.0f);
    EXPECT_FLOAT_EQ(m.elements[2][2], 90.0f);
#endif
}

TEST(Multiplication, Mat3Vec3) {
    Mat3 m = M3();
    Vec3 v = V3(0.0f, 0.0f, 0.0f);

    int counter = 1;
    for (int Column = 0; Column < 3; Column++) {
        for (int Row = 0; Row < 3; Row++) {
            m.elements[Column][Row] = counter++;
        }
    }

    for (int Row = 0; Row < 3; Row++) {
        v.elements[Row] = counter++;
    }

    {
        Vec3 result = mul_m3v3(m, v);
        EXPECT_FLOAT_EQ(result.elements[0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[2], 204.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = mul(m, v);
        EXPECT_FLOAT_EQ(result.elements[0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[2], 204.0f);
    }
    
    {
        Vec3 result = m * v;
        EXPECT_FLOAT_EQ(result.elements[0], 138.0f);
        EXPECT_FLOAT_EQ(result.elements[1], 171.0f);
        EXPECT_FLOAT_EQ(result.elements[2], 204.0f);
    }
#endif
}

TEST(Multiplication, Mat4Mat4)
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
        Mat4 result = mul_m4(m4_1, m4_2);
        EXPECT_FLOAT_EQ(result.elements[0][0], 538.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 612.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 686.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 760.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 650.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 740.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 830.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 920.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 762.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 868.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 974.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 1080.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 874.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 996.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 1118.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 1240.0f);
    }
#ifdef __cplusplus
    {
        Mat4 result = mul(m4_1, m4_2);
        EXPECT_FLOAT_EQ(result.elements[0][0], 538.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 612.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 686.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 760.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 650.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 740.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 830.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 920.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 762.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 868.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 974.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 1080.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 874.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 996.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 1118.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 1240.0f);
    }
    {
        Mat4 result = m4_1 * m4_2;
        EXPECT_FLOAT_EQ(result.elements[0][0], 538.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 612.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 686.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 760.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 650.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 740.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 830.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 920.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 762.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 868.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 974.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 1080.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 874.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 996.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 1118.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 1240.0f);
    }

    // At the time I wrote this, I intentionally omitted
    // the *= operator for matrices because matrix
    // multiplication is not commutative. (bvisness)
#endif
}

TEST(Multiplication, Mat4Scalar)
{
    Mat4 m4 = M4(); // will have 1 - 16
    float s = 3;

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
        Mat4 result = mul_m4f(m4, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 15.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 18.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 24.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 27.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 33.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 36.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 39.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 42.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 45.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 48.0f);
    }
#ifdef __cplusplus
    {
        Mat4 result = mul(m4, s);
        EXPECT_FLOAT_EQ(result.elements[0][0], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 15.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 18.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 24.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 27.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 33.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 36.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 39.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 42.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 45.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 48.0f);
    }
    {
        Mat4 result = m4 * s;
        EXPECT_FLOAT_EQ(result.elements[0][0], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 15.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 18.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 24.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 27.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 33.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 36.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 39.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 42.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 45.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 48.0f);
    }
    {
        Mat4 result = s * m4;
        EXPECT_FLOAT_EQ(result.elements[0][0], 3.0f);
        EXPECT_FLOAT_EQ(result.elements[0][1], 6.0f);
        EXPECT_FLOAT_EQ(result.elements[0][2], 9.0f);
        EXPECT_FLOAT_EQ(result.elements[0][3], 12.0f);
        EXPECT_FLOAT_EQ(result.elements[1][0], 15.0f);
        EXPECT_FLOAT_EQ(result.elements[1][1], 18.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f);
        EXPECT_FLOAT_EQ(result.elements[1][3], 24.0f);
        EXPECT_FLOAT_EQ(result.elements[2][0], 27.0f);
        EXPECT_FLOAT_EQ(result.elements[2][1], 30.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 33.0f);
        EXPECT_FLOAT_EQ(result.elements[2][3], 36.0f);
        EXPECT_FLOAT_EQ(result.elements[3][0], 39.0f);
        EXPECT_FLOAT_EQ(result.elements[3][1], 42.0f);
        EXPECT_FLOAT_EQ(result.elements[3][2], 45.0f);
        EXPECT_FLOAT_EQ(result.elements[3][3], 48.0f);
    }

    m4 *= s;
    EXPECT_FLOAT_EQ(m4.elements[0][0], 3.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][1], 6.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][2], 9.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][3], 12.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][0], 15.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][1], 18.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][2], 21.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][3], 24.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][0], 27.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][1], 30.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][2], 33.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][3], 36.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][0], 39.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][1], 42.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][2], 45.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][3], 48.0f);
#endif
}

TEST(Multiplication, Mat4Vec4)
{
    Mat4 m4 = M4(); // will have 1 - 16
    Vec4 v4 = V4(1.0f, 2.0f, 3.0f, 4.0f);

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
        Vec4 result = mul_m4v4(m4, v4);
        EXPECT_FLOAT_EQ(result.x, 90.0f);
        EXPECT_FLOAT_EQ(result.y, 100.0f);
        EXPECT_FLOAT_EQ(result.z, 110.0f);
        EXPECT_FLOAT_EQ(result.w, 120.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = mul(m4, v4);
        EXPECT_FLOAT_EQ(result.x, 90.0f);
        EXPECT_FLOAT_EQ(result.y, 100.0f);
        EXPECT_FLOAT_EQ(result.z, 110.0f);
        EXPECT_FLOAT_EQ(result.w, 120.0f);
    }
    {
        Vec4 result = m4 * v4;
        EXPECT_FLOAT_EQ(result.x, 90.0f);
        EXPECT_FLOAT_EQ(result.y, 100.0f);
        EXPECT_FLOAT_EQ(result.z, 110.0f);
        EXPECT_FLOAT_EQ(result.w, 120.0f);
    }

    // *= makes no sense for this particular case.
#endif
}

TEST(Multiplication, QuaternionQuaternion)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Quat result = mul_q(q1, q2);
        EXPECT_FLOAT_EQ(result.x, 24.0f);
        EXPECT_FLOAT_EQ(result.y, 48.0f);
        EXPECT_FLOAT_EQ(result.z, 48.0f);
        EXPECT_FLOAT_EQ(result.w, -6.0f);
    }
#ifdef __cplusplus
    {
        Quat result = mul(q1, q2);
        EXPECT_FLOAT_EQ(result.x, 24.0f);
        EXPECT_FLOAT_EQ(result.y, 48.0f);
        EXPECT_FLOAT_EQ(result.z, 48.0f);
        EXPECT_FLOAT_EQ(result.w, -6.0f);
    }
    {
        Quat result = q1 * q2;
        EXPECT_FLOAT_EQ(result.x, 24.0f);
        EXPECT_FLOAT_EQ(result.y, 48.0f);
        EXPECT_FLOAT_EQ(result.z, 48.0f);
        EXPECT_FLOAT_EQ(result.w, -6.0f);
    }

    // Like with matrices, we're not implementing the *=
    // operator for quaternions because quaternion multiplication
    // is not commutative.
#endif
}

TEST(Multiplication, QuaternionScalar)
{
    Quat q = Q(1.0f, 2.0f, 3.0f, 4.0f);
    float f = 2.0f;

    {
        Quat result = mul_qf(q, f);
        EXPECT_FLOAT_EQ(result.x, 2.0f);
        EXPECT_FLOAT_EQ(result.y, 4.0f);
        EXPECT_FLOAT_EQ(result.z, 6.0f);
        EXPECT_FLOAT_EQ(result.w, 8.0f);
    }
#ifdef __cplusplus
    {
        Quat result = mul(q, f);
        EXPECT_FLOAT_EQ(result.x, 2.0f);
        EXPECT_FLOAT_EQ(result.y, 4.0f);
        EXPECT_FLOAT_EQ(result.z, 6.0f);
        EXPECT_FLOAT_EQ(result.w, 8.0f);
    }
    {
        Quat result = q * f;
        EXPECT_FLOAT_EQ(result.x, 2.0f);
        EXPECT_FLOAT_EQ(result.y, 4.0f);
        EXPECT_FLOAT_EQ(result.z, 6.0f);
        EXPECT_FLOAT_EQ(result.w, 8.0f);
    }
    {
        Quat result = f * q;
        EXPECT_FLOAT_EQ(result.x, 2.0f);
        EXPECT_FLOAT_EQ(result.y, 4.0f);
        EXPECT_FLOAT_EQ(result.z, 6.0f);
        EXPECT_FLOAT_EQ(result.w, 8.0f);
    }

    q *= f;
    EXPECT_FLOAT_EQ(q.x, 2.0f);
    EXPECT_FLOAT_EQ(q.y, 4.0f);
    EXPECT_FLOAT_EQ(q.z, 6.0f);
    EXPECT_FLOAT_EQ(q.w, 8.0f);
#endif
}
