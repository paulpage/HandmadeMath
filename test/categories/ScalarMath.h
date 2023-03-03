#include "../HandmadeTest.h"

TEST(ScalarMath, Trigonometry)
{
    // We have to be a little looser with our equality constraint
    // because of floating-point precision issues.
    const float trigAbsError = 0.0001f;

    EXPECT_NEAR(m_sin(0.0f), 0.0f, trigAbsError);
    EXPECT_NEAR(m_sin(PI32 / 2), 1.0f, trigAbsError);
    EXPECT_NEAR(m_sin(PI32), 0.0f, trigAbsError);
    EXPECT_NEAR(m_sin(3 * PI32 / 2), -1.0f, trigAbsError);
    EXPECT_NEAR(m_sin(-PI32 / 2), -1.0f, trigAbsError);

    EXPECT_NEAR(m_cos(0.0f), 1.0f, trigAbsError);
    EXPECT_NEAR(m_cos(PI32 / 2), 0.0f, trigAbsError);
    EXPECT_NEAR(m_cos(PI32), -1.0f, trigAbsError);
    EXPECT_NEAR(m_cos(3 * PI32 / 2), 0.0f, trigAbsError);
    EXPECT_NEAR(m_cos(-PI32), -1.0f, trigAbsError);

    EXPECT_NEAR(m_tan(0.0f), 0.0f, trigAbsError);
    EXPECT_NEAR(m_tan(PI32 / 4), 1.0f, trigAbsError);
    EXPECT_NEAR(m_tan(3 * PI32 / 4), -1.0f, trigAbsError);
    EXPECT_NEAR(m_tan(PI32), 0.0f, trigAbsError);
    EXPECT_NEAR(m_tan(-PI32 / 4), -1.0f, trigAbsError);

    // This isn't the most rigorous because we're really just sanity-
    // checking that things work by default.
}

TEST(ScalarMath, SquareRoot)
{
    EXPECT_FLOAT_EQ(m_sqrt(16.0f), 4.0f);
}

TEST(ScalarMath, RSquareRootF)
{
    EXPECT_NEAR(invsqrt(10.0f), 0.31616211f, 0.0001f);
}

TEST(ScalarMath, Lerp)
{
    EXPECT_FLOAT_EQ(lerp(-2.0f, 0.0f, 2.0f), -2.0f);
    EXPECT_FLOAT_EQ(lerp(-2.0f, 0.5f, 2.0f), 0.0f);
    EXPECT_FLOAT_EQ(lerp(-2.0f, 1.0f, 2.0f), 2.0f);
}

TEST(ScalarMath, Clamp)
{
    EXPECT_FLOAT_EQ(clamp(-2.0f, 0.0f, 2.0f), 0.0f);
    EXPECT_FLOAT_EQ(clamp(-2.0f, -3.0f, 2.0f), -2.0f);
    EXPECT_FLOAT_EQ(clamp(-2.0f, 3.0f, 2.0f), 2.0f);
}
