#include <gtest/gtest.h>

#include "dlt_logger_config.h"

constexpr std::string_view RESOURCES_FOLDER{"resources/"};

// NOLINTBEGIN(readability-function-cognitive-complexity)

class LoggerConfigServiceFixture : public ::testing::Test
{
protected:
    void SetUp() override
    {
        empty_config_path_ = std::string(RESOURCES_FOLDER) + "empty_config.yaml";
        normal_config_path_ = std::string(RESOURCES_FOLDER) + "normal_config.yaml";
    }
    void TearDown() override {}

    // GTest fixture members can be protected, false positive
    // NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes)
    std::string empty_path_;
    std::string empty_config_path_;
    std::string normal_config_path_;
    // NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes)
};

using namespace common::logger::config;

// Here is no implementation for update yet.

TEST_F(LoggerConfigServiceFixture, TestUpdateEmptyPathExceptNoException)
{
    DltLoggerConfigService config_service;
    EXPECT_NO_THROW(config_service.update());
}

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
class LoggerConfigServiceParamFixture : public ::testing::Test, public testing::WithParamInterface<std::string>
{
protected:
    void SetUp() override {};
};

INSTANTIATE_TEST_SUITE_P(IllFormedConfigTests, LoggerConfigServiceParamFixture,
                         testing::Values(std::string(RESOURCES_FOLDER) + "ill_format_config.yaml", std::string(RESOURCES_FOLDER) + "no_app_id.yaml",
                                         std::string(RESOURCES_FOLDER) + "no_context_descr.yaml",
                                         std::string(RESOURCES_FOLDER) + "no_context_id.yaml", std::string(RESOURCES_FOLDER) + "no_context.yaml",
                                         std::string(RESOURCES_FOLDER) + "no_context_sequence.yaml",
                                         std::string(RESOURCES_FOLDER) + "no_file_path.yaml", std::string(RESOURCES_FOLDER) + "no_logger.yaml",
                                         std::string(RESOURCES_FOLDER) + "no_mode.yaml",
                                         std::string(RESOURCES_FOLDER) + "empty_logger_section.yaml"));

TEST_P(LoggerConfigServiceParamFixture, TestLoadIllFormedExceptFalse)
{
    DltLoggerConfigService config_service;
    const auto& current_path = GetParam();
    EXPECT_FALSE(config_service.load(current_path));
}
// NOLINTEND(readability-function-cognitive-complexity)