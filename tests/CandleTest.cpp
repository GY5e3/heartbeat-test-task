#include "CandleTest.hpp"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(CandleTest, body_contains_positive)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool result = m_candle.body_contains(151.0);

    EXPECT_TRUE(result);
}
TEST_F(CandleTest, body_contains_edge_cases)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool upperBound = m_candle.body_contains(152.0);
    bool lowerBound = m_candle.body_contains(150.0);

    EXPECT_TRUE(upperBound);
    EXPECT_TRUE(lowerBound);
}
TEST_F(CandleTest, body_contains_out_of_range)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool upperBound = m_candle.body_contains(152.1);
    bool lowerBound = m_candle.body_contains(149.9);

    EXPECT_FALSE(upperBound);
    EXPECT_FALSE(lowerBound);
}
TEST_F(CandleTest, body_contains_bearish_candle)
{
    m_candle = Candle(152.0, 155.0, 145.0, 150.0);

    bool result = m_candle.body_contains(151.0);

    EXPECT_TRUE(result);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(CandleTest, contains_positive)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool result = m_candle.contains(150.0);

    EXPECT_TRUE(result);
}
TEST_F(CandleTest, contains_edge_cases)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool upperBound = m_candle.contains(155.0);
    bool lowerBound = m_candle.contains(145.0);

    EXPECT_TRUE(upperBound);
    EXPECT_TRUE(lowerBound);
}
TEST_F(CandleTest, contains_out_of_range)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    bool upperBound = m_candle.contains(155.1);
    bool lowerBound = m_candle.contains(144.9);

    EXPECT_FALSE(upperBound);
    EXPECT_FALSE(lowerBound);
}
TEST_F(CandleTest, contains_incorrect_max_and_min)
{
    m_candle = Candle(150.0, 145.0, 155.0, 152.0);

    bool result = m_candle.contains(150.0);

    EXPECT_FALSE(result);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(CandleTest, full_size_positive)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    Price result = m_candle.full_size();

    EXPECT_EQ(result, 10.0);
}
TEST_F(CandleTest, full_size_edge_case)
{
    m_candle = Candle(150.0, 150.0, 150.0, 150.0);

    Price result = m_candle.full_size();

    EXPECT_EQ(result, 0.0);
}
TEST_F(CandleTest, full_size_incorrect_max_and_min)
{
    m_candle = Candle(150.0, 145.0, 155.0, 152.0);

    Price result = m_candle.full_size();

    EXPECT_EQ(result, 10.0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(CandleTest, body_size_positive)
{
    m_candle = Candle(150.0, 155.0, 145.0, 152.0);

    Price result = m_candle.body_size();

    EXPECT_EQ(result, 2.0);
}
TEST_F(CandleTest, body_size_edge_case)
{
    m_candle = Candle(150.0, 155.0, 145.0, 150.0);

    Price result = m_candle.body_size();

    EXPECT_EQ(result, 0.0);
}
TEST_F(CandleTest, body_size_bearish_candle)
{
    m_candle = Candle(150.0, 145.0, 155.0, 152.0);

    Price result = m_candle.body_size();

    EXPECT_EQ(result, 2.0);
}