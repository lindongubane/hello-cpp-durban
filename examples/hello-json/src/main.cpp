#include <iostream>
#include <fstream>
#include <string_view>
#include <filesystem>
#include <optional>
#include <nlohmann/json.hpp>

#include "person.hpp"

namespace fs = std::filesystem;
// For more information about nlohmann json, go to https://github.com/nlohmann/json or https://nlohmann.github.io/json/.
using json = nlohmann::json;

std::optional<fs::path> json_file_exists(std::string_view exe_path, std::string_view json_file)
{
    // If you run the program with an absolute path, or if you run it from inside its directory,
    // current path with be the exact path where the executable is, and where our json file(s) should be.
    if (auto path = fs::current_path().append(json_file); fs::exists(path))
    {
        std::cout << path << "\n";
        return path;
    }

    // Alternatively, if we have the first command line argument, this should tell us how the executable was invoked,
    // and then we should get a (usually) relative path to the file we want.
    if(auto otherPath = fs::path(exe_path).parent_path().append(json_file); fs::exists(otherPath))
    {
        std::cout << otherPath << "\n";
        return otherPath;
    }

    return std::nullopt;
}

int main(int argc, const char** argv)
{
    // Sample part 1
    if (auto path = json_file_exists(argv[0], "hello.json"); path.has_value())
    {
        std::ifstream hello_file(path.value());
        auto hello_json = json::parse(hello_file);

        std::cout << hello_json["mainMessage"].get<std::string_view>() << '\n';
        std::cout << "Here are some places you might know:\n";

        for (auto& city : hello_json["someCities"])
        {
            std::cout << "* " << city.get<std::string_view>() << '\n';
        }

        std::cout << hello_json << '\n';
    }
    else
    {
        std::cerr << "hello.json not found.\n";
    }

    // Sample part 2
    hello::person someone = { "B.J.", "Blazkowicz", 69  };

    json someone_as_json = someone;

    std::cout << someone_as_json << '\n';

    std::ofstream someone_as_file("someone.json", std::ios::trunc);
    someone_as_file << someone_as_json.dump(4);

    return 0;
}