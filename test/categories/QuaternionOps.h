#include "../HandmadeTest.h"

TEST(QuaternionOps, Inverse)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat inverse = InvQ(q1);

    Quat result = mul_q(q1, inverse);

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
    EXPECT_FLOAT_EQ(result.w, 1.0f);
}

TEST(QuaternionOps, Dot)
{
    Quat q1 = Q(1.0f, 2.0f, 3.0f, 4.0f);
    Quat q2 = Q(5.0f, 6.0f, 7.0f, 8.0f);

    {
        float result = dot_q(q1, q2);
        EXPECT_FLOAT_EQ(result, 70.0f);
    }
#ifdef __cplusplus
    {
        float result = dot(q1, q2);
        EXPECT_FLOAT_EQ(result, 70.0f);
    }
#endif
}

TEST(QuaternionOps, Normalize)
{
    Quat q = Q(1.0f, 2.0f, 3.0f, 4.0f);

    {
        Quat result = norm_q(q);
        EXPECT_NEAR(result.x, 0.1825741858f, 0.001f);
        EXPECT_NEAR(result.y, 0.3651483717f, 0.001f);
        EXPECT_NEAR(result.z, 0.5477225575f, 0.001f);
        EXPECT_NEAR(result.w, 0.7302967433f, 0.001f);
    }
#ifdef __cplusplus
    {
        Quat result = norm(q);
        EXPECT_NEAR(result.x, 0.1825741858f, 0.001f);
        EXPECT_NEAR(result.y, 0.3651483717f, 0.001f);
        EXPECT_NEAR(result.z, 0.5477225575f, 0.001f);
        EXPECT_NEAR(result.w, 0.7302967433f, 0.001f);
    }
#endif
}

TEST(QuaternionOps, NLerp)
{
    Quat from = Q(0.0f, 0.0f, 0.0f, 1.0f);
    Quat to = Q(0.5f, 0.5f, -0.5f, 0.5f);

    Quat result = lerp_n(from, 0.5f, to);
    EXPECT_NEAR(result.x, 0.28867513f, 0.001f);
    EXPECT_NEAR(result.y, 0.28867513f, 0.001f);
    EXPECT_NEAR(result.z, -0.28867513f, 0.001f);
    EXPECT_NEAR(result.w, 0.86602540f, 0.001f);
}

TEST(QuaternionOps, SLerp)
{
    Quat from = Q(0.0f, 0.0f, 0.0f, 1.0f);
    Quat to = Q(0.5f, 0.5f, -0.5f, 0.5f);

    {
        Quat result = lerp_s(from, 0.0f, to);
        EXPECT_NEAR(result.x, 0.0f, 0.001f);
        EXPECT_NEAR(result.y, 0.0f, 0.001f);
        EXPECT_NEAR(result.z, 0.0f, 0.001f);
        EXPECT_NEAR(result.w, 1.0, 0.001f);
    }
    {
        Quat result = lerp_s(from, 0.25f, to);
        EXPECT_NEAR(result.x, 0.149429246f, 0.001f);
        EXPECT_NEAR(result.y, 0.149429246f, 0.001f);
        EXPECT_NEAR(result.z, -0.149429246f, 0.001f);
        EXPECT_NEAR(result.w, 0.965925812f, 0.001f);
    }
    {
        Quat result = lerp_s(from, 0.5f, to);
        EXPECT_NEAR(result.x, 0.28867513f, 0.001f);
        EXPECT_NEAR(result.y, 0.28867513f, 0.001f);
        EXPECT_NEAR(result.z, -0.28867513f, 0.001f);
        EXPECT_NEAR(result.w, 0.86602540f, 0.001f);
    }
    {
        Quat result = lerp_s(from, 0.75f, to);
        EXPECT_NEAR(result.x, 0.40824830f, 0.001f);
        EXPECT_NEAR(result.y, 0.40824830f, 0.001f);
        EXPECT_NEAR(result.z, -0.40824830f, 0.001f);
        EXPECT_NEAR(result.w, 0.70710676f, 0.001f);
    }
        {
        Quat result = lerp_s(from, 1.0f, to);
        EXPECT_NEAR(result.x, 0.5f, 0.001f);
        EXPECT_NEAR(result.y, 0.5f, 0.001f);
        EXPECT_NEAR(result.z, -0.5f, 0.001f);
        EXPECT_NEAR(result.w, 0.5f, 0.001f);
    }
}

TEST(QuaternionOps, QuatToMat4)
{
    const float abs_error = 0.001f;

    Quat rot = Q(0.707107f, 0.0f, 0.0f, 0.707107f);

    Mat4 result = q_to_m4(rot);

    EXPECT_NEAR(result.elements[0][0], 1.0f, abs_error);
    EXPECT_NEAR(result.elements[0][1], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[0][2], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[0][3], 0.0f, abs_error);

    EXPECT_NEAR(result.elements[1][0], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[1][1], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[1][2], 1.0f, abs_error);
    EXPECT_NEAR(result.elements[1][3], 0.0f, abs_error);

    EXPECT_NEAR(result.elements[2][0], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[2][1], -1.0f, abs_error);
    EXPECT_NEAR(result.elements[2][2], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[2][3], 0.0f, abs_error);

    EXPECT_NEAR(result.elements[3][0], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[3][1], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[3][2], 0.0f, abs_error);
    EXPECT_NEAR(result.elements[3][3], 1.0f, abs_error);
}

TEST(QuaternionOps, Mat4ToQuat)
{
    const float abs_error = 0.0001f;

    // Rotate 90 degrees on the x axis
    {
        Mat4 m = rotate_rh(angle_deg(90.0f), V3(1, 0, 0));
        Quat result = m4_to_q_rh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, sinf, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 90 degrees on the y axis (axis not normalized, just for fun)
    {
        Mat4 m = rotate_rh(angle_deg(90.0f), V3(0, 2, 0));
        Quat result = m4_to_q_rh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, 0.0f, abs_error);
        EXPECT_NEAR(result.y, sinf, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 90 degrees on the z axis
    {
        Mat4 m = rotate_rh(angle_deg(90.0f), V3(0, 0, 1));
        Quat result = m4_to_q_rh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, 0.0f, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, sinf, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 45 degrees on the x axis (this hits case 4)
    {
        Mat4 m = rotate_rh(angle_deg(45.0f), V3(1, 0, 0));
        Quat result = m4_to_q_rh(m);

        float cosf = 0.9238795325f; // cos(90/2 degrees)
        float sinf = 0.3826834324f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, sinf, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    /* NOTE(lcf): left-handed cases. Since both Rotate and M4ToQ are LH results should be
        the same with no changes to input. */
    // Rotate 90 degrees on the x axis
    {
        Mat4 m = rotate_lh(angle_deg(90.0f), V3(1, 0, 0));
        Quat result = m4_to_q_lh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, sinf, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 90 degrees on the y axis (axis not normalized, just for fun)
    {
        Mat4 m = rotate_lh(angle_deg(90.0f), V3(0, 2, 0));
        Quat result = m4_to_q_lh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, 0.0f, abs_error);
        EXPECT_NEAR(result.y, sinf, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 90 degrees on the z axis
    {
        Mat4 m = rotate_lh(angle_deg(90.0f), V3(0, 0, 1));
        Quat result = m4_to_q_lh(m);

        float cosf = 0.707107f; // cos(90/2 degrees)
        float sinf = 0.707107f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, 0.0f, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, sinf, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }

    // Rotate 45 degrees on the x axis (this hits case 4)
    {
        Mat4 m = rotate_lh(angle_deg(45.0f), V3(1, 0, 0));
        Quat result = m4_to_q_lh(m);

        float cosf = 0.9238795325f; // cos(90/2 degrees)
        float sinf = 0.3826834324f; // sin(90/2 degrees)

        EXPECT_NEAR(result.x, sinf, abs_error);
        EXPECT_NEAR(result.y, 0.0f, abs_error);
        EXPECT_NEAR(result.z, 0.0f, abs_error);
        EXPECT_NEAR(result.w, cosf, abs_error);
    }
}

TEST(QuaternionOps, FromAxisAngle)
{
    Vec3 axis = V3(1.0f, 0.0f, 0.0f);
    float angle = PI32 / 2.0f;

    {
        Quat result = QFromAxisAngle_RH(axis, angle);
        EXPECT_NEAR(result.x, 0.707107f, 0.001f);
        EXPECT_NEAR(result.y, 0.0f, 0.001f);
        EXPECT_NEAR(result.z, 0.0f, 0.001f);
        EXPECT_NEAR(result.w, 0.707107f, 0.001f);
    }
    {
        Quat result = q_from_axis_angle_lh(axis, angle);
        EXPECT_NEAR(result.x, -0.707107f, 0.001f);
        EXPECT_NEAR(result.y, 0.0f, 0.001f);
        EXPECT_NEAR(result.z, 0.0f, 0.001f);
        EXPECT_NEAR(result.w, 0.707107f, 0.001f);
    }
}
