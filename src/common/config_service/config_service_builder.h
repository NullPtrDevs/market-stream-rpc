#pragma once

#include <memory>
#include <type_traits>

#include "i_config_service.h"

namespace config_service
{

template <typename S, typename U>
concept DerivedFromBase = requires(S type) { []<typename V>(IConfigService<V>&) {}(type); };

template <typename T>
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
        if constexpr (DerivedFromBase<T, void>)
        {
            return std::make_unique<T>();
        }
        return nullptr;
    };
};

}  // namespace config_service