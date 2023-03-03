#include "../HandmadeTest.h"

TEST(Projection, Orthographic)
{
#define ORTHO_BOUNDS -8.0f, 12.0f, 5.0f, 10.0f, 1.0f, 100.0f

    // right-handed
    {
        // Near and far distances correspond to negative z, hence the z coordinates here are negative.
        Vec4 minCorner = V4(-8.0f, 5.0f, -1.0f, 1.0);
        Vec4 maxCorner = V4(12.0f, 10.0f, -100.0f, 1.0);

        // z from -1 to 1 (GL convention)
        {
            Mat4 projection = orthographic_rh_no(ORTHO_BOUNDS);
            EXPECT_V4_EQ(mul_m4v4(projection, minCorner), V4(-1.0f, -1.0f, -1.0f, 1.0f));
            EXPECT_V4_EQ(mul_m4v4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }

        // z from 0 to 1 (DX convention)
        {
            Mat4 projection = orthographic_rh_zo(ORTHO_BOUNDS);
            EXPECT_V4_EQ(mul_m4v4(projection, minCorner), V4(-1.0f, -1.0f, 0.0f, 1.0f));
            EXPECT_V4_EQ(mul_m4v4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }
    }

    // left-handed
    {
        // Near and far distances correspond to positive z, hence the z coordinates here are positive.
        Vec4 minCorner = V4(-8.0f, 5.0f, 1.0f, 1.0);
        Vec4 maxCorner = V4(12.0f, 10.0f, 100.0f, 1.0);

        // z from -1 to 1 (GL convention)
        {
            Mat4 projection = orthographic_lh_no(ORTHO_BOUNDS);
            EXPECT_V4_EQ(mul_m4v4(projection, minCorner), V4(-1.0f, -1.0f, -1.0f, 1.0f));
            EXPECT_V4_EQ(mul_m4v4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }

        // z from 0 to 1 (DX convention)
        {
            Mat4 projection = orthographic_lh_zo(ORTHO_BOUNDS);
            EXPECT_V4_EQ(mul_m4v4(projection, minCorner), V4(-1.0f, -1.0f, 0.0f, 1.0f));
            EXPECT_V4_EQ(mul_m4v4(projection, maxCorner), V4(1.0f, 1.0f, 1.0f, 1.0f));
        }
    }
}

TEST(Projection, Perspective)
{
    // right-handed
    {
        // z from -1 to 1 (GL convention)
        {
            Mat4 projection = perspective_rh_no(angle_deg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, -1.0f, 1.0f);
            EXPECT_V4_EQ(mul_m4v4(projection, original), V4(2.5f, 5.0f, -1.0f, 1.0f));
        }

        // z from 0 to 1 (DX convention)
        {
            Mat4 projection = perspective_rh_zo(angle_deg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, -1.0f, 1.0f);
            EXPECT_V4_EQ(mul_m4v4(projection, original), V4(2.5f, 5.0f, 0.0f, 1.0f));
        }
    }

    // left-handed
    {
        // z from -1 to 1 (GL convention)
        {
            Mat4 projection = perspective_lh_no(angle_deg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, 1.0f, 1.0f);
            EXPECT_V4_EQ(mul_m4v4(projection, original), V4(2.5f, 5.0f, -1.0f, 1.0f));
        }

        // z from 0 to 1 (DX convention)
        {
            Mat4 projection = perspective_lh_zo(angle_deg(90.0f), 2.0f, 1.0f, 15.0f);
            Vec4 original = V4(5.0f, 5.0f, 1.0f, 1.0f);
            EXPECT_V4_EQ(mul_m4v4(projection, original), V4(2.5f, 5.0f, 0.0f, 1.0f));
        }
    }
}
