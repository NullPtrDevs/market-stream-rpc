#include <gtest/gtest.h>

#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>

#include "common/logger/dlt_logger.h"

TEST(DltLoggerTest, ReturnsSameSingletonInstance)
{
    auto& first_instance = common::logger::DltLogger::instance();
    auto& second_instance = common::logger::DltLogger::instance();

    EXPECT_EQ(&first_instance, &second_instance);
}

TEST(DltLoggerTest, LoggingHelpersDoNotThrowWhenLoggerIsNotInitialized)
{
    EXPECT_NO_THROW(common::logger::log_info("info message"));
    EXPECT_NO_THROW(common::logger::log_error("error message"));
    EXPECT_NO_THROW(common::logger::log_debug("debug message"));
    EXPECT_NO_THROW(common::logger::log_warn("warning message"));
    EXPECT_NO_THROW(common::logger::log_fatal("fatal message"));
}

TEST(DltLoggerTest, StopIsIdempotentWhenLoggerIsNotInitialized)
{
    EXPECT_NO_THROW(common::logger::DltLogger::instance().stop());
    EXPECT_NO_THROW(common::logger::DltLogger::instance().stop());
}