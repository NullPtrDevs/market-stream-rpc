#pragma once
#include <string>
#include <vector>

#include "i_config_service.h"

namespace common::logger::config
{

struct DltLoggerContext
{
    std::string id_;
    std::string description_;
};
struct DltLoggerConfig
{
    std::string app_id_;
    std::string app_description_;
    std::string mode_;
    std::string file_path_;
    std::vector<DltLoggerContext> context_list_;
};

class DltLoggerConfigService final : public config_service::IConfigService<DltLoggerConfig>
{
public:
    DltLoggerConfigService() = default;
    DltLoggerConfigService(const DltLoggerConfigService&) = delete;
    auto operator=(const DltLoggerConfigService&) -> DltLoggerConfigService& = delete;
    DltLoggerConfigService(DltLoggerConfigService&&) = delete;
    auto operator=(DltLoggerConfigService&&) -> DltLoggerConfigService& = delete;
    ~DltLoggerConfigService() override = default;

    auto load(const std::string& config_path) -> bool override;
    auto update() -> DltLoggerConfig override;
    [[nodiscard]] auto get_config_data() const -> DltLoggerConfig override;

private:
    DltLoggerConfig dlt_config_;
};

}  // namespace common::logger::config