#include "../HandmadeTest.h"

TEST(Initialization, Vectors)
{
    //
    // Test vec2
    //
    Vec2 v2 = V2(1.0f, 2.0f);

    EXPECT_FLOAT_EQ(v2.x, 1.0f);
    EXPECT_FLOAT_EQ(v2.y, 2.0f);
    EXPECT_FLOAT_EQ(v2.u, 1.0f);
    EXPECT_FLOAT_EQ(v2.v, 2.0f);
    EXPECT_FLOAT_EQ(v2.left, 1.0f);
    EXPECT_FLOAT_EQ(v2.right, 2.0f);
    EXPECT_FLOAT_EQ(v2.width, 1.0f);
    EXPECT_FLOAT_EQ(v2.height, 2.0f);
    EXPECT_FLOAT_EQ(v2.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v2.elements[1], 2.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(v2[0], 1.0f);
    EXPECT_FLOAT_EQ(v2[1], 2.0f);
#endif

    //
    // Test vec3
    //
    Vec3 v3 = V3(1.0f, 2.0f, 3.0f);

    EXPECT_FLOAT_EQ(v3.x, 1.0f);
    EXPECT_FLOAT_EQ(v3.y, 2.0f);
    EXPECT_FLOAT_EQ(v3.z, 3.0f);
    EXPECT_FLOAT_EQ(v3.u, 1.0f);
    EXPECT_FLOAT_EQ(v3.v, 2.0f);
    EXPECT_FLOAT_EQ(v3.w, 3.0f);
    EXPECT_FLOAT_EQ(v3.r, 1.0f);
    EXPECT_FLOAT_EQ(v3.g, 2.0f);
    EXPECT_FLOAT_EQ(v3.b, 3.0f);
    EXPECT_FLOAT_EQ(v3.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v3.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v3.elements[2], 3.0f);
    EXPECT_FLOAT_EQ(v3.xy.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v3.xy.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v3.yz.elements[0], 2.0f);
    EXPECT_FLOAT_EQ(v3.yz.elements[1], 3.0f);
    EXPECT_FLOAT_EQ(v3.uv.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v3.uv.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v3.vw.elements[0], 2.0f);
    EXPECT_FLOAT_EQ(v3.vw.elements[1], 3.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(v3[0], 1.0f);
    EXPECT_FLOAT_EQ(v3[1], 2.0f);
    EXPECT_FLOAT_EQ(v3[2], 3.0f);
#endif

    //
    // Test vec4
    //
    Vec4 v4 = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 v4v = V4V(v3, 4.0f);

    EXPECT_FLOAT_EQ(v4.x, 1.0f);
    EXPECT_FLOAT_EQ(v4.y, 2.0f);
    EXPECT_FLOAT_EQ(v4.z, 3.0f);
    EXPECT_FLOAT_EQ(v4.w, 4.0f);
    EXPECT_FLOAT_EQ(v4.r, 1.0f);
    EXPECT_FLOAT_EQ(v4.g, 2.0f);
    EXPECT_FLOAT_EQ(v4.b, 3.0f);
    EXPECT_FLOAT_EQ(v4.A, 4.0f);
    EXPECT_FLOAT_EQ(v4.xy.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4.xy.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4.yz.elements[0], 2.0f);
    EXPECT_FLOAT_EQ(v4.yz.elements[1], 3.0f);
    EXPECT_FLOAT_EQ(v4.zw.elements[0], 3.0f);
    EXPECT_FLOAT_EQ(v4.zw.elements[1], 4.0f);
    EXPECT_FLOAT_EQ(v4.xy.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4.xy.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4.xyz.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4.xyz.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4.xyz.elements[2], 3.0f);
    EXPECT_FLOAT_EQ(v4.RGB.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4.RGB.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4.RGB.elements[2], 3.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(v4[0], 1.0f);
    EXPECT_FLOAT_EQ(v4[1], 2.0f);
    EXPECT_FLOAT_EQ(v4[2], 3.0f);
    EXPECT_FLOAT_EQ(v4[3], 4.0f);
#endif

    EXPECT_FLOAT_EQ(v4v.x, 1.0f);
    EXPECT_FLOAT_EQ(v4v.y, 2.0f);
    EXPECT_FLOAT_EQ(v4v.z, 3.0f);
    EXPECT_FLOAT_EQ(v4v.w, 4.0f);
    EXPECT_FLOAT_EQ(v4v.r, 1.0f);
    EXPECT_FLOAT_EQ(v4v.g, 2.0f);
    EXPECT_FLOAT_EQ(v4v.b, 3.0f);
    EXPECT_FLOAT_EQ(v4v.A, 4.0f);
    EXPECT_FLOAT_EQ(v4v.xy.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4v.xy.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4v.yz.elements[0], 2.0f);
    EXPECT_FLOAT_EQ(v4v.yz.elements[1], 3.0f);
    EXPECT_FLOAT_EQ(v4v.zw.elements[0], 3.0f);
    EXPECT_FLOAT_EQ(v4v.zw.elements[1], 4.0f);
    EXPECT_FLOAT_EQ(v4v.xy.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4v.xy.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4v.xyz.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4v.xyz.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4v.xyz.elements[2], 3.0f);
    EXPECT_FLOAT_EQ(v4v.RGB.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(v4v.RGB.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(v4v.RGB.elements[2], 3.0f);
#ifdef __cplusplus
    EXPECT_FLOAT_EQ(v4v[0], 1.0f);
    EXPECT_FLOAT_EQ(v4v[1], 2.0f);
    EXPECT_FLOAT_EQ(v4v[2], 3.0f);
    EXPECT_FLOAT_EQ(v4v[3], 4.0f);
#endif
}

TEST(Initialization, MatrixEmpty)
{
    //
    // Test mat2
    //
    Mat2 m2 = M2();
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            EXPECT_FLOAT_EQ(m2.elements[Column][Row], 0.0f);
#ifdef __cplusplus
            EXPECT_FLOAT_EQ(m2[Column][Row], 0.0f);
#endif
        }
    }

    //
    // Test mat3
    //
    Mat3 m3 = M3();
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            EXPECT_FLOAT_EQ(m3.elements[Column][Row], 0.0f);
#ifdef __cplusplus
            EXPECT_FLOAT_EQ(m3[Column][Row], 0.0f);
#endif
        }
    }

    //
    // Test mat4
    //
    Mat4 m4 = M4();
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            EXPECT_FLOAT_EQ(m4.elements[Column][Row], 0.0f);
#ifdef __cplusplus
            EXPECT_FLOAT_EQ(m4[Column][Row], 0.0f);
#endif
        }
    }
}

TEST(Initialization, MatrixDiagonal)
{
    //
    // Test mat2
    //
    Mat2 m2d = M2D(1.0f);
    for (int Column = 0; Column < 2; ++Column)
    {
        for (int Row = 0; Row < 2; ++Row)
        {
            if (Column == Row) {
                EXPECT_FLOAT_EQ(m2d.elements[Column][Row], 1.0f);
            } else {
                EXPECT_FLOAT_EQ(m2d.elements[Column][Row], 0.0f);
            }
        }
    }

    //
    // Test mat3
    //
    Mat3 m3d = M3D(1.0f);
    for (int Column = 0; Column < 3; ++Column)
    {
        for (int Row = 0; Row < 3; ++Row)
        {
            if (Column == Row) {
                EXPECT_FLOAT_EQ(m3d.elements[Column][Row], 1.0f);
            } else {
                EXPECT_FLOAT_EQ(m3d.elements[Column][Row], 0.0f);
            }
        }
    }

    //
    // Test mat4
    //
    Mat4 m4d = M4D(1.0f);
    for (int Column = 0; Column < 4; ++Column)
    {
        for (int Row = 0; Row < 4; ++Row)
        {
            if (Column == Row) {
                EXPECT_FLOAT_EQ(m4d.elements[Column][Row], 1.0f);
            } else {
                EXPECT_FLOAT_EQ(m4d.elements[Column][Row], 0.0f);
            }
        }
    }
}

TEST(Initialization, Quaternion)
{
    Quat q = Q(1.0f, 2.0f, 3.0f, 4.0f);

    EXPECT_FLOAT_EQ(q.x, 1.0f);
    EXPECT_FLOAT_EQ(q.y, 2.0f);
    EXPECT_FLOAT_EQ(q.z, 3.0f);
    EXPECT_FLOAT_EQ(q.w, 4.0f);

    EXPECT_FLOAT_EQ(q.elements[0], 1.0f);
    EXPECT_FLOAT_EQ(q.elements[1], 2.0f);
    EXPECT_FLOAT_EQ(q.elements[2], 3.0f);
    EXPECT_FLOAT_EQ(q.elements[3], 4.0f);

    Vec4 v = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Quat qv = QV4(v);

    EXPECT_FLOAT_EQ(qv.x, 1.0f);
    EXPECT_FLOAT_EQ(qv.y, 2.0f);
    EXPECT_FLOAT_EQ(qv.z, 3.0f);
    EXPECT_FLOAT_EQ(qv.w, 4.0f);
}

#ifdef __cplusplus
TEST(Initialization, MatrixOverloads)
{
    // Operator overloads for matrix columns must allow mutation.

    //
    // Test mat2
    //
    Mat2 m2 = {0};
    m2[0][0] = 1.0f;
    m2[0][1] = 2.0f;
    m2[1][0] = 3.0f;
    m2[1][1] = 4.0f;
    EXPECT_FLOAT_EQ(m2.elements[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m2.elements[0][1], 2.0f);
    EXPECT_FLOAT_EQ(m2.elements[1][0], 3.0f);
    EXPECT_FLOAT_EQ(m2.elements[1][1], 4.0f);

    //
    // Test mat3
    //
    Mat3 m3 = {0};
    m3[0][0] = 1.0f;
    m3[0][1] = 2.0f;
    m3[0][2] = 3.0f;
    m3[1][0] = 4.0f;
    m3[1][1] = 5.0f;
    m3[1][2] = 6.0f;
    m3[2][0] = 7.0f;
    m3[2][1] = 8.0f;
    m3[2][2] = 9.0f;
    EXPECT_FLOAT_EQ(m3.elements[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m3.elements[0][1], 2.0f);
    EXPECT_FLOAT_EQ(m3.elements[0][2], 3.0f);
    EXPECT_FLOAT_EQ(m3.elements[1][0], 4.0f);
    EXPECT_FLOAT_EQ(m3.elements[1][1], 5.0f);
    EXPECT_FLOAT_EQ(m3.elements[1][2], 6.0f);
    EXPECT_FLOAT_EQ(m3.elements[2][0], 7.0f);
    EXPECT_FLOAT_EQ(m3.elements[2][1], 8.0f);
    EXPECT_FLOAT_EQ(m3.elements[2][2], 9.0f);

    //
    // Test mat4
    //
    Mat4 m4 = {0};
    m4[0][0] = 1.0f;
    m4[0][1] = 2.0f;
    m4[0][2] = 3.0f;
    m4[0][3] = 4.0f;
    m4[1][0] = 5.0f;
    m4[1][1] = 6.0f;
    m4[1][2] = 7.0f;
    m4[1][3] = 8.0f;
    m4[2][0] = 9.0f;
    m4[2][1] = 10.0f;
    m4[2][2] = 11.0f;
    m4[2][3] = 12.0f;
    m4[3][0] = 13.0f;
    m4[3][1] = 14.0f;
    m4[3][2] = 15.0f;
    m4[3][3] = 16.0f;
    EXPECT_FLOAT_EQ(m4.elements[0][0], 1.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][1], 2.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][2], 3.0f);
    EXPECT_FLOAT_EQ(m4.elements[0][3], 4.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][0], 5.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][1], 6.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][2], 7.0f);
    EXPECT_FLOAT_EQ(m4.elements[1][3], 8.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][0], 9.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][1], 10.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][2], 11.0f);
    EXPECT_FLOAT_EQ(m4.elements[2][3], 12.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][0], 13.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][1], 14.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][2], 15.0f);
    EXPECT_FLOAT_EQ(m4.elements[3][3], 16.0f);
}
#endif
