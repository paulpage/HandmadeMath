#include "../HandmadeTest.h"

TEST(Addition, Vec2)
{
    Vec2 v2_1 = V2(1.0f, 2.0f);
    Vec2 v2_2 = V2(3.0f, 4.0f);

    {
        Vec2 result = add_v2(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }
#ifdef __cplusplus
    {
        Vec2 result = add(v2_1, v2_2);
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }
    {
        Vec2 result = v2_1 + v2_2;
        EXPECT_FLOAT_EQ(result.x, 4.0f);
        EXPECT_FLOAT_EQ(result.y, 6.0f);
    }

    v2_1 += v2_2;
    EXPECT_FLOAT_EQ(v2_1.x, 4.0f);
    EXPECT_FLOAT_EQ(v2_1.y, 6.0f);
#endif
}

TEST(Addition, Vec3)
{
    Vec3 v3_1 = V3(1.0f, 2.0f, 3.0f);
    Vec3 v3_2 = V3(4.0f, 5.0f, 6.0f);

    {
        Vec3 result = add_v3(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 7.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }
#ifdef __cplusplus
    {
        Vec3 result = add(v3_1, v3_2);
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 7.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }
    {
        Vec3 result = v3_1 + v3_2;
        EXPECT_FLOAT_EQ(result.x, 5.0f);
        EXPECT_FLOAT_EQ(result.y, 7.0f);
        EXPECT_FLOAT_EQ(result.z, 9.0f);
    }

    v3_1 += v3_2;
    EXPECT_FLOAT_EQ(v3_1.x, 5.0f);
    EXPECT_FLOAT_EQ(v3_1.y, 7.0f);
    EXPECT_FLOAT_EQ(v3_1.z, 9.0f);
#endif
}

TEST(Addition, Vec4)
{
    Vec4 v4_1 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4_2 = V4(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Vec4 result = add_v4(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
#ifdef __cplusplus
    {
        Vec4 result = add(v4_1, v4_2);
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
    {
        Vec4 result = v4_1 + v4_2;
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }

    v4_1 += v4_2;
    EXPECT_FLOAT_EQ(v4_1.x, 6.0f);
    EXPECT_FLOAT_EQ(v4_1.y, 8.0f);
    EXPECT_FLOAT_EQ(v4_1.z, 10.0f);
    EXPECT_FLOAT_EQ(v4_1.w, 12.0f);
#endif
}

TEST(Addition, Mat2)
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
        Mat2 result = add_m2(a, b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 12.0f); 
    }

#ifdef __cplusplus
    {
        Mat2 result = add(a, b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 12.0f); 
    }
    {
        Mat2 result = a + b;
        EXPECT_FLOAT_EQ(result.elements[0][0], 6.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 8.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 10.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 12.0f); 
    }
    a += b;
    EXPECT_FLOAT_EQ(a.elements[0][0], 6.0f); 
    EXPECT_FLOAT_EQ(a.elements[0][1], 8.0f); 
    EXPECT_FLOAT_EQ(a.elements[1][0], 10.0f); 
    EXPECT_FLOAT_EQ(a.elements[1][1], 12.0f); 
#endif
}

TEST(Addition, Mat3) 
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
        Mat3 result = add_m3(a, b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 27.0f);   
    }

#ifdef __cplusplus
    {
        Mat3 result = add(a, b);
        EXPECT_FLOAT_EQ(result.elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 27.0f);   
    }
    {
        Mat3 result = a + b;
        EXPECT_FLOAT_EQ(result.elements[0][0], 11.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][1], 13.0f); 
        EXPECT_FLOAT_EQ(result.elements[0][2], 15.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][0], 17.0f); 
        EXPECT_FLOAT_EQ(result.elements[1][1], 19.0f);
        EXPECT_FLOAT_EQ(result.elements[1][2], 21.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][0], 23.0f); 
        EXPECT_FLOAT_EQ(result.elements[2][1], 25.0f);
        EXPECT_FLOAT_EQ(result.elements[2][2], 27.0f);   
    }
    a += b;
    EXPECT_FLOAT_EQ(a.elements[0][0], 11.0f); 
    EXPECT_FLOAT_EQ(a.elements[0][1], 13.0f); 
    EXPECT_FLOAT_EQ(a.elements[0][2], 15.0f); 
    EXPECT_FLOAT_EQ(a.elements[1][0], 17.0f); 
    EXPECT_FLOAT_EQ(a.elements[1][1], 19.0f);
    EXPECT_FLOAT_EQ(a.elements[1][2], 21.0f); 
    EXPECT_FLOAT_EQ(a.elements[2][0], 23.0f); 
    EXPECT_FLOAT_EQ(a.elements[2][1], 25.0f);
    EXPECT_FLOAT_EQ(a.elements[2][2], 27.0f);   
#endif  
}

TEST(Addition, Mat4)
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
        Mat4 result = add_m4(m4_1, m4_2);
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }
#ifdef __cplusplus
    {
        Mat4 result = add(m4_1, m4_2);
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }
    {
        Mat4 result = m4_1 + m4_2;
        float Expected = 18.0f;
        for (int Column = 0; Column < 4; ++Column)
        {
            for (int Row = 0; Row < 4; ++Row)
            {
                EXPECT_FLOAT_EQ(result.elements[Column][Row], Expected);
                Expected += 2.0f;
            }
        }
    }

    m4_1 += m4_2;
    float Expected = 18.0f;
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            EXPECT_FLOAT_EQ(m4_1.elements[Column][Row], Expected);
            Expected += 2.0f;
        }
    }
#endif
}

TEST(Addition, Quaternion)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        Quat result = add_q(q1, q2);
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
#ifdef __cplusplus
    {
        Quat result = add(q1, q2);
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }
    {
        Quat result = q1 + q2;
        EXPECT_FLOAT_EQ(result.x, 6.0f);
        EXPECT_FLOAT_EQ(result.y, 8.0f);
        EXPECT_FLOAT_EQ(result.z, 10.0f);
        EXPECT_FLOAT_EQ(result.w, 12.0f);
    }

    q1 += q2;
    EXPECT_FLOAT_EQ(q1.x, 6.0f);
    EXPECT_FLOAT_EQ(q1.y, 8.0f);
    EXPECT_FLOAT_EQ(q1.z, 10.0f);
    EXPECT_FLOAT_EQ(q1.w, 12.0f);
#endif
}
