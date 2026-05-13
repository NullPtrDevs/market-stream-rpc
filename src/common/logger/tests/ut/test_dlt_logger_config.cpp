#include <gtest/gtest.h>

#include <filesystem>

#include "dlt_logger_config.h"

namespace fs = std::filesystem;

// NOLINTBEGIN(readability-function-cognitive-complexity)
class LoggerConfigServiceFixture : public ::testing::Test
{
protected:
    void SetUp() override
    {
        empty_config_path_ = resources_folder_ / "empty_config.yaml";
        normal_config_path_ = resources_folder_ / "normal_config.yaml";
        ill_format_config_path_ = resources_folder_ / "ill_format_config.yaml";
    }
    void TearDown() override {}
    // GTest fixture members can be protected, false positive
    // NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes)
    fs::path resources_folder_{"resources"};
    fs::path empty_path_{""};
    fs::path empty_config_path_{""};
    fs::path normal_config_path_{""};
    fs::path ill_format_config_path_{""};
    // NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes)
};

using namespace common::logger::config;

TEST_F(LoggerConfigServiceFixture, TestLoadEmptyPathExceptNoException)
{
    DltLoggerConfigService config_service;
    EXPECT_NO_THROW(config_service.load(empty_path_));
}

TEST_F(LoggerConfigServiceFixture, TestLoadEmptyPathExceptReturnFalse)
{
    DltLoggerConfigService config_service;
    EXPECT_FALSE(config_service.load(empty_path_));
}

TEST_F(LoggerConfigServiceFixture, TestLoadCorrectPathExceptNoException)
{
    DltLoggerConfigService config_service;
    EXPECT_NO_THROW(config_service.load(normal_config_path_));
}

TEST_F(LoggerConfigServiceFixture, TestLoadCorrectPathExceptTrue)
{
    DltLoggerConfigService config_service;
    EXPECT_TRUE(config_service.load(normal_config_path_));
}

TEST_F(LoggerConfigServiceFixture, TestLoadCorrectPathExceptValidData)
{
    DltLoggerConfigService config_service;
    EXPECT_TRUE(config_service.load(normal_config_path_));

    auto config_data = config_service.get_config_data();
    ASSERT_FALSE(config_data.app_id_.empty());
    ASSERT_FALSE(config_data.app_description_.empty());
    ASSERT_FALSE(config_data.file_path_.empty());
    ASSERT_FALSE(config_data.mode_.empty());
    ASSERT_FALSE(config_data.context_list_.empty());
    for (const auto& context : config_data.context_list_)
    {
        ASSERT_FALSE(context.id_.empty());
        ASSERT_FALSE(context.description_.empty());
    }
}

TEST_F(LoggerConfigServiceFixture, TestLoadIllFormedExceptFalse)
{
    DltLoggerConfigService config_service;
    EXPECT_FALSE(config_service.load(ill_format_config_path_));
}

// NOLINTEND(readability-function-cognitive-complexity)