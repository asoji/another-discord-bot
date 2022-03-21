//
// Created by Aubrey on 3/21/2022.
//
#include <toml.hpp>
#include "dpp/dpp.h"
#include <toml/parser.hpp>
#include "dpp/snowflake.h"

#ifndef ANOTHER_DISCORD_BOT_MAIN_HPP
#define ANOTHER_DISCORD_BOT_MAIN_HPP

const auto configFile = toml::parse("config/config.toml");
const auto englishFile = toml::parse("config/en_us.toml");

const auto token = toml::find<std::string>(configFile, "config", "token");
const auto guildID = toml::find<dpp::snowflake>(configFile, "config", "guildID");

const auto howdyDesc = toml::find<std::string>(englishFile, "description", "howdy");
const auto howdyOutput = toml::find<std::string>(englishFile, "output", "howdy");

const auto testModalDesc = toml::find<std::string>(englishFile, "description", "testModal");
const auto testModalTitle = toml::find<std::string>(englishFile, "modals", "test_modal", "title");
const auto testModalComponent1Label = toml::find<std::string>(englishFile, "modals", "test_modal", "component1", "label");
const auto testModalComponent1Placeholder = toml::find<std::string>(englishFile, "modals", "test_modal", "component1", "placeholder");
const auto testModalComponent2Label = toml::find<std::string>(englishFile, "modals", "test_modal", "component2", "label");
const auto testModalComponent2Placeholder = toml::find<std::string>(englishFile, "modals", "test_modal", "component2", "placeholder");


#endif //ANOTHER_DISCORD_BOT_MAIN_HPP
