#include "CandleTest.hpp"

TEST_F(CandleTest, body_contains_positive)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    EXPECT_TRUE(m_candle.body_contains(151.0));
}
TEST_F(CandleTest, body_contains_edge_cases)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    EXPECT_TRUE(m_candle.body_contains(152.0));
    EXPECT_TRUE(m_candle.body_contains(150.0));
}
TEST_F(CandleTest, body_contains_out_of_range)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    EXPECT_FALSE(m_candle.body_contains(152.1));
    EXPECT_FALSE(m_candle.body_contains(149.9));
}
TEST_F(CandleTest, body_contains_bearish_candle)
{
    m_candle = Candle(152.0, 155.0, 145.0, 150.0);

    EXPECT_TRUE(m_candle.body_contains(151.0));
}