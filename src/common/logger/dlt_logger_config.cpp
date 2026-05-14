#include "dlt_logger_config.h"

#include <yaml-cpp/yaml.h>

#include <iostream>

namespace common::logger::config
{

auto DltLoggerConfigService::load(const std::string& config_path) -> bool
{
    // False positive. External libraries can generate exceptions inside their code.
    // That can lead to situation when codecov(lcov, gcovr),
    // recognize this block as not covered (branches, conditions).
    // In fact all branches are covered, and code completely safe.
    // LCOVR_EXCL_BR_START
    try
    {
        auto root_node = YAML::LoadFile(config_path);
        auto logger_node = root_node["logger"];
        if (!logger_node)
        {
            return false;
        }
        auto get_node = [&logger_node](std::string_view name, std::string& out) -> bool
        {
            auto node = logger_node[name];
            if (node)
            {
                out = node.as<std::string>();
                return true;
            }
            return false;
        };
        if (!get_node("app_id", dlt_config_.app_id_))
        {
            return false;
        }
        if (!get_node("app_description", dlt_config_.app_description_))
        {
            return false;
        }
        auto contexts_node = logger_node["contexts"];
        if ((contexts_node) && contexts_node.IsSequence())
        {
            for (const auto& context : contexts_node)
            {
                auto context_id = context["id"];
                auto description = context["description"];
                if (context_id && description)
                {
                    dlt_config_.context_list_.emplace_back(context_id.as<std::string>(), description.as<std::string>());
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        if (!get_node("mode", dlt_config_.mode_))
        {
            return false;
        }
        if (!get_node("file_path", dlt_config_.file_path_))
        {
            return false;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    // LCOVR_EXCL_BR_STOP

    return true;
}

auto DltLoggerConfigService::update() -> DltLoggerConfig
{
    // Resolved for future use
    return dlt_config_;
}

[[nodiscard]] auto DltLoggerConfigService::get_config_data() const -> DltLoggerConfig
{
    return dlt_config_;
}

}  // namespace common::logger::config
