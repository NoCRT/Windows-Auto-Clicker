#include "SFML/Window.hpp"
#include "random.hpp"
#include <iostream>
#include <windows.h>

using random = effolkronium::random_static;

void click()
{
    INPUT Input = {0};
    // Input.type = INPUT_KEYBOARD;

    // left down
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left down
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
    bool toggle = true;
    while (true)
    {
        static sf::Clock timer;
        if (timer.getElapsedTime().asSeconds() > 1)
        {
            if (!toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle = true;
                timer.restart();
            }
            else if (toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle = false;
                timer.restart();
            }
        }

        if (toggle && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            click();
        }

        Sleep(random::get(1, 5));
    }

    std::cout << "exited loop\n";
    return EXIT_SUCCESS;
}