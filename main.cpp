#include "SFML/Window.hpp"
#include "random.hpp"
#include <iostream>
#include <windows.h>

using random = effolkronium::random_static;

void LeftClick()
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
}

void RightClick()
{
    INPUT Input = {0};
    // Input.type = INPUT_KEYBOARD;

    // left down
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
    // potentialy take args to define the time between presses or create bindings to 2 unused keys
    while (true)
    {
        bool toggle = true;
        if (!toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
        {
            toggle = true;
        }
        else if (toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
        {
            toggle = false;
        }

        if (toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
        {
            LeftClick();
        }

        Sleep(random::get(40, 70));
    }

    std::cout << "exited loop\n";
    return EXIT_SUCCESS;
}