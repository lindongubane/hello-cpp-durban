#include <iostream>
#include <fstream>
#include <string_view>
#include <nlohmann/json.hpp>

#include "person.hpp"

// For more information about nlohmann json, go to https://github.com/nlohmann/json or https://nlohmann.github.io/json/.
using json = nlohmann::json;

int main()
{
    // Sample part 1
    std::ifstream hello_file("hello.json");
    auto hello_json = json::parse(hello_file);

    std::cout << hello_json["mainMessage"].get<std::string_view>() << '\n';
    std::cout << "Here are some places you might know:\n";

    for (auto& city : hello_json["someCities"])
    {
        std::cout << "* " << city.get<std::string_view>() << '\n';
    }

    std::cout << hello_json << '\n';

    // Sample part 2
    hello::person someone = { "B.J.", "Blazkowicz", 69  };

    json someone_as_json = someone;

    std::cout << someone_as_json << '\n';

    std::ofstream someone_as_file("someone.json", std::ios::trunc);
    someone_as_file << someone_as_json.dump(4);

    return 0;
}