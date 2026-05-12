#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

class DltConfig final
{
public:
    enum class Mode : std::uint8_t {
        Daemon,
        File
    };

    struct OptContext {
        std::string id;
        std::string description;
    };

    std::string app_id;
    std::string app_description;
    std::vector<OptContext> contexts;
    Mode mode = Mode::Daemon;
    std::string file_path;

    static auto from_yaml(const std::string& file_path) -> DltConfig
    {
        YAML::Node root = YAML::LoadFile(file_path);
        const YAML::Node logger = root["logger"];
        if (!logger) {
            throw std::runtime_error("Missing logger configuration");
        }

        DltConfig config;
        config.app_id = logger["app_id"].as<std::string>();
        config.app_description = logger["app_description"].as<std::string>();
        config.mode = parse_mode(logger["mode"].as<std::string>());
        config.file_path = logger["file_path"].as<std::string>();

        for (const auto& context : logger["contexts"]) {
            config.contexts.push_back({
                .id = context["id"].as<std::string>(),
                .description = context["description"].as<std::string>()
            });
        }

        return config;
    }

private:
    static auto parse_mode(const std::string& mode) -> Mode
    {
        if (mode == "daemon") {
            return Mode::Daemon;
        }

        if (mode == "file") {
            return Mode::File;
        }

        throw std::runtime_error("Invalid DLT logger mode: " + mode);
    }
};
