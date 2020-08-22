#include <uWebSockets/App.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    auto app = uWS::App();
    app.get("/people", [](auto* res, auto* req)
    {
        const static auto people = json
                {
                        {
                                {"firstName", "Harry"},
                                {"lastName", "Potter"},
                        },
                        {
                                {"firstName", "Ron"},
                                {"lastName", "Weasley"},
                        },
                        {
                                {"firstName", "Hermione"},
                                {"lastName", "Granger"},
                        }
                };

        res->writeHeader("Content-Type", "application-json; charset=utf-8");
        res->end(people.dump());
    });

    app.get("/mechs", [](auto* res, auto* req)
    {
        std::string_view accepts = req->getHeader("accept");
        const static auto mechs = json
                {
                        {
                                {"name", "Timber Wolf"},
                                {"class", "Heavy"},
                                {"altName", "Mad Cat"}
                        },
                        {
                                {"name", "Bushwacker"},
                                {"class", "Medium"},
                        },
                        {
                                {"name", "Atlas"},
                                {"class", "Assault"},
                        }
                };

        if (accepts.find("application/msgpack") != std::string_view::npos)
        {
            auto packedData = json::to_msgpack(mechs);
            auto packedView = std::string_view(reinterpret_cast<std::string_view::pointer>(packedData.data()), packedData.size());
            res->writeHeader("Content-Type", "application/msgpack; charset=utf-8");
            res->end(packedView);
        }
        else
        {
            res->writeHeader("Content-Type", "application/json; charset=utf-8");
            res->end(mechs.dump());
        }
    });


    app.listen(3000, [](auto* token)
    {
        if (token)
        {
            std::cout << "Listening on port " << 3000 << std::endl;
        }
    });

    app.run();

    return 0;
}