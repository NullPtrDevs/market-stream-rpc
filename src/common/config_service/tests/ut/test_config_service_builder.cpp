#include <gtest/gtest.h>

#include <type_traits>

#include "config_service_builder.h"

struct TestConfigService
{
};

TEST(ConfigServiceBuilderTest, IsReturnValueNullPtr)
{
    auto ret_val = config_service::ConfigServiceBuilder<TestConfigService>::build();
    ASSERT_TRUE(ret_val.get() == nullptr);
}

TEST(ConfigServiceBuilderTest, IsReturnValueNotNullPtr)
{
    struct TestData
    {
    };
    struct TestConfigServiceInherit : public config_service::IConfigService<TestData>
    {
        auto load(const std::string& raw_yaml) -> bool override
        {
            return true;
        };
        auto update() -> TestData override
        {
            return {};
        };
        [[nodiscard]] auto get_config_data() const -> TestData override
        {
            return {};
        };
    };
    auto ret_val = config_service::ConfigServiceBuilder<TestConfigServiceInherit>::build();
    ASSERT_TRUE(ret_val.get() != nullptr);
}
