#include "../HandmadeTest.h"

TEST(Equality, Vec2)
{
    Vec2 a = V2(1.0f, 2.0f);
    Vec2 b = V2(1.0f, 2.0f);
    Vec2 c = V2(3.0f, 4.0f);

    EXPECT_TRUE(eq_v2(a, b));
    EXPECT_FALSE(eq_v2(a, c));

#ifdef __cplusplus
    EXPECT_TRUE(eq(a, b));
    EXPECT_FALSE(eq(a, c));

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);

    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
#endif
}

TEST(Equality, Vec3)
{
    Vec3 a = V3(1.0f, 2.0f, 3.0f);
    Vec3 b = V3(1.0f, 2.0f, 3.0f);
    Vec3 c = V3(4.0f, 5.0f, 6.0f);

    EXPECT_TRUE(eq_v3(a, b));
    EXPECT_FALSE(eq_v3(a, c));

#ifdef __cplusplus
    EXPECT_TRUE(eq(a, b));
    EXPECT_FALSE(eq(a, c));

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);

    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
#endif
}

TEST(Equality, Vec4)
{
    Vec4 a = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 b = V4(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 c = V4(5.0f, 6.0f, 7.0f, 8.0f);

    EXPECT_TRUE(eq_v4(a, b));
    EXPECT_FALSE(eq_v4(a, c));

#ifdef __cplusplus
    EXPECT_TRUE(eq(a, b));
    EXPECT_FALSE(eq(a, c));

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);

    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
#endif
}
