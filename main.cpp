#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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

// auto_on.wav
// auto_off.wav

int main()
{
    sf::SoundBuffer toggle_off_buffer;
    toggle_off_buffer.loadFromFile("auto_off.wav");
    sf::Sound toggle_off(toggle_off_buffer);
    
    sf::SoundBuffer toggle_on_buffer;
    toggle_on_buffer.loadFromFile("auto_on.wav");
    sf::Sound toggle_on(toggle_on_buffer);

    bool toggle = false;
    std::clog << "STATUS : OFF";
    while (true)
    {
        static sf::Clock timer;
        if (timer.getElapsedTime().asSeconds() > 1)
        {
            if (!toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle_on.play();
                toggle = true;
                system("cls");
                std::clog << "STATUS : ON";
                timer.restart();
            }
            else if (toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle_off.play();
                toggle = false;
                system("cls");
                std::clog << "STATUS : OFF";
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