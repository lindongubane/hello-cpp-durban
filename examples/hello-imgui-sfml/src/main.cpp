#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <array>
#include <functional>

// Based on code from the following article: https://eliasdaler.github.io/using-imgui-with-sfml-pt1/

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    sf::Color bgColor;

    std::array color = {0.f, 0.f, 0.f};
    std::array<char, 255> windowTitle = {"Hello ImGui + SFML"};

    window.setTitle(windowTitle.data());
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;

    std::vector<std::function<void()>> labels;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // Do some GUI work here.
        {
            ImGui::Begin("C++ Durban"); // begin window

            // When the value is changed, true is returned
            if (ImGui::ColorEdit3("Background color", color.data()))
            {
                bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
                bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
                bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
            }

            // Window title text edit
            if (ImGui::InputText("Window title", windowTitle.data(), windowTitle.size()))
            {
                window.setTitle(windowTitle.data());
            }

            if (ImGui::Button("Add more"))
            {
                labels.emplace_back([]()
                {
                    ImGui::PushItemWidth(1);
                    ImGui::LabelText("More!!!", "");
                });
            }

            for (auto& label : labels)
            {
                label();
            }

            ImGui::End();
        }

        window.clear(bgColor); // fill background with color
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}