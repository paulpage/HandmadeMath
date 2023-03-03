#include "../HandmadeTest.h"

TEST(Transformations, Translate)
{
    Mat4 TRANSLATE = translate(V3(1.0f, -3.0f, 6.0f));

    Vec3 original = V3(1.0f, 2.0f, 3.0f);
    Vec4 translated = mul_m4v4(TRANSLATE, V4V(original, 1));

    EXPECT_NEAR(translated.x, 2.0f, 0.001f);
    EXPECT_NEAR(translated.y, -1.0f, 0.001f);
    EXPECT_NEAR(translated.z, 9.0f, 0.001f);
    EXPECT_NEAR(translated.w, 1.0f, 0.001f);
}

TEST(Transformations, Rotate)
{
    Vec3 original = V3(1.0f, 1.0f, 1.0f);

    Mat4 rotateX = rotate_rh(angle_deg(90.0f), V3(1, 0, 0));
    Vec4 rotatedX = mul_m4v4(rotateX, V4V(original, 1));
    EXPECT_NEAR(rotatedX.x, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.y, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedX.w, 1.0f, 0.001f);

    Mat4 rotateY = rotate_rh(angle_deg(90.0f), V3(0, 1, 0));
    Vec4 rotatedY = mul_m4v4(rotateY, V4V(original, 1));
    EXPECT_NEAR(rotatedY.x, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.y, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.z, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedY.w, 1.0f, 0.001f);

    Mat4 rotateZ = rotate_rh(angle_deg(90.0f), V3(0, 0, 1));
    Vec4 rotatedZ = mul_m4v4(rotateZ, V4V(original, 1));
    EXPECT_NEAR(rotatedZ.x, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.y, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZ.w, 1.0f, 0.001f);

    Mat4 rotateZLH = rotate_lh(angle_deg(90.0f), V3(0, 0, 1));
    Vec4 rotatedZLH = mul_m4v4(rotateZLH, V4V(original, 1));
    EXPECT_NEAR(rotatedZLH.x, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.y, -1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.z, 1.0f, 0.001f);
    EXPECT_NEAR(rotatedZLH.w, 1.0f, 0.001f);
}

TEST(Transformations, Scale)
{
    Mat4 SCALE = scale(V3(2.0f, -3.0f, 0.5f));

    Vec3 original = V3(1.0f, 2.0f, 3.0f);
    Vec4 scaled = mul_m4v4(SCALE, V4V(original, 1));

    EXPECT_NEAR(scaled.x, 2.0f, 0.001f);
    EXPECT_NEAR(scaled.y, -6.0f, 0.001f);
    EXPECT_NEAR(scaled.z, 1.5f, 0.001f);
    EXPECT_NEAR(scaled.w, 1.0f, 0.001f);
}

TEST(Transformations, LookAt)
{
    const float abs_error = 0.001f;

    {    Mat4 result = look_at_rh(V3(1.0f, 0.0f, 0.0f), V3(0.0f, 2.0f, 1.0f), V3(2.0f, 1.0f, 1.0f));

        EXPECT_NEAR(result.elements[0][0], 0.169031f, abs_error);
        EXPECT_NEAR(result.elements[0][1], 0.897085f, abs_error);
        EXPECT_NEAR(result.elements[0][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.elements[0][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[1][0], 0.507093f, abs_error);
        EXPECT_NEAR(result.elements[1][1], 0.276026f, abs_error);
        EXPECT_NEAR(result.elements[1][2], -0.816497f, abs_error);
        EXPECT_NEAR(result.elements[1][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[2][0], -0.845154f, abs_error);
        EXPECT_NEAR(result.elements[2][1], 0.345033f, abs_error);
        EXPECT_NEAR(result.elements[2][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.elements[2][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[3][0], -0.169031f, abs_error);
        EXPECT_NEAR(result.elements[3][1], -0.897085f, abs_error);
        EXPECT_NEAR(result.elements[3][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.elements[3][3], 1.0f, abs_error);
    }
    {    
        Mat4 result = look_at_lh(V3(1.0f, 0.0f, 0.0f), V3(0.0f, 2.0f, 1.0f), V3(2.0f, 1.0f, 1.0f));

        EXPECT_NEAR(result.elements[0][0], -0.169031f, abs_error);
        EXPECT_NEAR(result.elements[0][1], 0.897085f, abs_error);
        EXPECT_NEAR(result.elements[0][2], -0.408248f, abs_error);
        EXPECT_NEAR(result.elements[0][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[1][0], -0.507093f, abs_error);
        EXPECT_NEAR(result.elements[1][1], 0.276026f, abs_error);
        EXPECT_NEAR(result.elements[1][2], 0.816497f, abs_error);
        EXPECT_NEAR(result.elements[1][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[2][0], 0.845154f, abs_error);
        EXPECT_NEAR(result.elements[2][1], 0.345033f, abs_error);
        EXPECT_NEAR(result.elements[2][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.elements[2][3], 0.0f, abs_error);
        EXPECT_NEAR(result.elements[3][0], 0.169031f, abs_error);
        EXPECT_NEAR(result.elements[3][1], -0.897085f, abs_error);
        EXPECT_NEAR(result.elements[3][2], 0.408248f, abs_error);
        EXPECT_NEAR(result.elements[3][3], 1.0f, abs_error);
    }
}
