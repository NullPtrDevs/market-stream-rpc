#pragma once

#include <yaml-cpp/yaml.h>

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

class DltConfig final
{
public:
    enum class Mode : std::uint8_t
    {
        Daemon,
        File
    };

    struct OptContext
        std::string id_;
        std::string description_;
        std::string description_;
    };

    std::string app_id_;
    std::string app_description_;
    std::vector<OptContext> contexts_;
    Mode mode_ = Mode::Daemon;
    std::string file_path_;

    static auto from_yaml(const std::string& file_path) -> DltConfig
    {
        YAML::Node root = YAML::LoadFile(file_path);
        const YAML::Node logger = root["logger"];
        if (!logger)
        {
            throw std::runtime_error("Missing logger configuration");
        }

        DltConfig config;
        config.app_id_ = logger["app_id"].as<std::string>();
        config.app_description_ = logger["app_description"].as<std::string>();
        config.mode_ = parse_mode(logger["mode"].as<std::string>());
        config.file_path_ = logger["file_path"].as<std::string>();

        for (const auto& context : logger["contexts"])
        {
            config.contexts_.push_back({.id_ = context["id"].as<std::string>(), .description_ = context["description"].as<std::string>()});
        }

        return config;
    }

private:
    static auto parse_mode(const std::string& mode) -> Mode
    {
        if (mode == "daemon")
        {
            return Mode::Daemon;
        }

        if (mode == "file")
        {
            return Mode::File;
        }

        throw std::runtime_error("Invalid DLT logger mode: " + mode);
    }
};
