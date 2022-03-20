#include <dpp/dpp.h>
#include <toml.hpp>
#include <iostream>

const auto configFile = toml::parse("config.toml");
const auto token = toml::find<std::string>(configFile, "config", "token");
const auto guildID = toml::find<dpp::snowflake>(configFile, "config", "guildID");

int main() {
    dpp::cluster bot(token);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_interaction_create([](const dpp::interaction_create_t& event){
        if (event.command.get_command_name() == "howdy") {
            event.reply("Howdy nerd.");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t event){
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(dpp::slashcommand("howdy", "Say Howdy to the bot!", bot.me.id), guildID);
        }
    });

    bot.start(false);
}