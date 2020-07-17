#ifndef HELLO_JSON_PERSON_HPP
#define HELLO_JSON_PERSON_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace hello
{
    using json = nlohmann::json;

    struct person
    {
        std::string first_name;
        std::string last_name;
        int age;
    };

    void to_json(json& output, const person& input) {
        output = json{{"firstName", input.first_name}, {"lastName", input.last_name}, {"age", input.age}};
    }

    void from_json(const json& input, person& output) {
        input.at("name").get_to(output.first_name);
        input.at("address").get_to(output.last_name);
        input.at("age").get_to(output.age);
    }
}

#endif //HELLO_JSON_PERSON_HPP
