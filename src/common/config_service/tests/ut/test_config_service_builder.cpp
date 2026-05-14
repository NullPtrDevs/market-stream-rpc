#include <gtest/gtest.h>

#include "config_service_builder.h"

struct TestConfigService
{
};

TEST(ConfigServiceBuilderTest, IsReturnValueNotNullPtr)
{
    struct TestData
    {
    };
    // Don't need to calculate coverage of unit tests itself.
    // LCOV_EXCL_START
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
    // LCOV_EXCL_STOP
    auto ret_val = config_service::ConfigServiceBuilder<TestConfigServiceInherit>::build();
    ASSERT_TRUE(ret_val.get() != nullptr);
}
