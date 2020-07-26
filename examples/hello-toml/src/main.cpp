#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string_view>
#include <filesystem>
#include <optional>
#include <toml11/toml.hpp>

namespace fs = std::filesystem;

std::optional<fs::path> find_file(std::string_view some_file)
{
    auto current_path = fs::current_path();

    for(auto& item : fs::recursive_directory_iterator(current_path))
    {
        if (item.is_regular_file() && item.path().filename() == some_file)
        {
            return item.path();
        }
    }

    return std::nullopt;
}

int main()
{
    // Sample part 1
    if (auto path = find_file("hello.toml"); path.has_value())
    {
        const auto hello_toml = toml::parse(path.value().string());

        const auto title = toml::find<std::string>(hello_toml, "title");
        std::cout << "The title in hello.toml is " << title << '\n';

        const auto &database = toml::find(hello_toml, "database");
        std::cout << "Our database settings are: " << '\n';
        std::cout << '\t' << toml::find<std::string>(database, "server") << '\n';

        const auto ports = toml::find<std::vector<int>>(database, "ports");
        std::cout << '\t' << "Ports:\n";
        for (auto &port : ports)
        {
            std::cout << "\t\t" << port << '\n';
        }

        const auto &servers = toml::find<toml::table>(hello_toml, "servers");
        std::cout << '\t' << "Servers:\n";
        for (auto &server : servers)
        {
            std::cout << "\t\t" << server.first << ": " << toml::find(server.second, "ip") << '\n';
        }
    } else
    {
        std::cerr << "hello.toml not found.\n";
    }

    // Sample part 2
    toml::value our_config;
    toml::table our_server {
        {"server_name", "C++ Durban"},
        {"invite_link", "https://discord.gg/YsZuNmr"}
    };

    // Just an alternative way to the above for creating a table.
    toml::table our_database;
    our_database["address"] = "localhost";
    our_database["port"] = "1010";
    our_database["username"] = "cpp_durban";
    our_database["password"] = "join_us";

    our_config["discord"] = our_server;
    our_config["database"] = our_database;

    std::ofstream our_config_as_file("special-config.toml", std::ios::trunc);
    our_config_as_file << our_config;

    return 0;
}