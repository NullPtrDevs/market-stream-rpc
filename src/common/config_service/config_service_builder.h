#pragma once

#include <memory>

#include "i_config_service.h"

namespace config_service
{

template <typename ConfigServiceT>
concept DerivedFromBase = requires(ConfigServiceT type) { []<typename ConfigData>(IConfigService<ConfigData>&) {}(type); };

template <DerivedFromBase T>
class ConfigServiceBuilder
{
public:
    using IConfigServicePtr = std::unique_ptr<T>;

    ConfigServiceBuilder() = delete;
    ConfigServiceBuilder(const ConfigServiceBuilder&) = delete;
    auto operator=(const ConfigServiceBuilder&) -> ConfigServiceBuilder& = delete;
    ConfigServiceBuilder(ConfigServiceBuilder&&) = delete;
    auto operator=(ConfigServiceBuilder&&) -> ConfigServiceBuilder& = delete;
    ~ConfigServiceBuilder() = default;

    static auto build() -> IConfigServicePtr
    {
        return std::make_unique<T>();
    };
};

}  // namespace config_service