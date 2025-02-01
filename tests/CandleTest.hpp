#pragma once

#include <sstream>
#include <iostream>
#include <streambuf>

#include <gtest/gtest.h>

#include "candle.h"

class CandleTest: public testing::Test
{
protected:
    Candle m_candle;
};
