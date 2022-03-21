//
// Created by Aubrey on 3/20/2022.
//

#include "main.hpp"
#include <dpp/dpp.h>
#include <toml.hpp>
#include <iostream>

int main() {
    dpp::cluster bot(token);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t event){
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(dpp::slashcommand("howdy", howdyDesc, bot.me.id), guildID);
            bot.guild_command_create(dpp::slashcommand("dialog", testModalDesc, bot.me.id), guildID);
        }
    });

    bot.on_interaction_create([](const dpp::interaction_create_t& event){
        if (event.command.get_command_name() == "howdy") {
            event.reply(howdyOutput);
        }

        if (event.command.get_command_name() == "dialog") {
            dpp::interaction_modal_response testModal("test_modal", testModalTitle);

            testModal.add_component(
                    dpp::component().
                            set_label(testModalComponent1Label).
                            set_id("field_id").
                            set_type(dpp::cot_text).
                            set_placeholder(testModalComponent1Placeholder).
                            set_min_length(1).
                            set_max_length(2000).
                            set_text_style(dpp::text_short));

            testModal.add_row();

            testModal.add_component(
                    dpp::component().
                            set_label(testModalComponent2Label).
                            set_id("field_id_2").
                            set_type(dpp::cot_selectmenu).
                            set_placeholder(testModalComponent2Placeholder).
                            set_min_length(1).
                            set_max_length(2000).
                            set_text_style(dpp::text_short));


            event.dialog(testModal);
        }
    });

    bot.on_form_submit([&](const dpp::form_submit_t & event) {
        std::string thing1 = std::get<std::string>(event.components[0].components[0].value);
        std::string thing2 = std::get<std::string>(event.components[1].components[0].value);
        dpp::message m;
        m.set_content(testModalComponent1Label + ": " + thing1 + "\n"
                        + testModalComponent2Label + ": " + thing2 + " <:wigged_nubert:943323764282781716>");
        event.reply(m);
    });

    bot.start(false);
}