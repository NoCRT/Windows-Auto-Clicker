#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <windows.h>

//using random = effolkronium::random_static;

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

    // this is neeeded for sfml to detect that the macro is still running
    // this causes some isues that need to be resolved like firing the loop when it
    // shouldn't, This also adds an extra click to the end of the loop.
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));
}

// auto_on.wav : https://freesound.org/people/deleted_user_4772965/sounds/256839/
// auto_off.wav : https://freesound.org/people/RutgerMuller/sounds/51168/

int main()
{
    sf::SoundBuffer toggle_off_buffer;
    toggle_off_buffer.loadFromFile("auto_off.wav");
    sf::Sound toggle_off(toggle_off_buffer);
    
    sf::SoundBuffer toggle_on_buffer;
    toggle_on_buffer.loadFromFile("auto_on.wav");
    sf::Sound toggle_on(toggle_on_buffer);

    int delay = 90;

    bool toggle = false;
    std::clog << "STATUS : OFF";
    
    while (true)
    {
        // toggle functionality on or off
        static sf::Clock toggle_timer;
        if (toggle_timer.getElapsedTime().asSeconds() > 1)
        {
            if (!toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle_on.play();
                toggle = true;
                system("cls");
                std::clog << "STATUS : ON";
                toggle_timer.restart();
            }
            else if (toggle && sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
            {
                toggle_off.play();
                toggle = false;
                system("cls");
                std::clog << "STATUS : OFF";
                toggle_timer.restart();
            }
        }

        // increase and decrease delay inbetween shots
        static sf::Clock delay_timer;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
        {
            if (delay <= 120 && delay_timer.getElapsedTime().asMilliseconds() >= 250)
            {
                delay += 5;
                delay_timer.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
        {
            if (delay >= 60 && delay_timer.getElapsedTime().asMilliseconds() >= 250)
            {
                delay -= 5;
                delay_timer.restart();
            }
        }
        

        if (toggle && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            static sf::Clock click_timer;

            // there is a weird bug where if the mouse is clicked and unclicked and dragged quick enough it
            // still fires LEFT_CLICK even though its not pysicaly pressed.
            // this might be because too many events were being fired off and some errer happens somwhere
            // as this is reduced significantly with a slower click rate.
            //if (click_timer.getElapsedTime().asMilliseconds() > 80) // 23cps : max = 180cps @ 10
            
            if (click_timer.getElapsedTime().asMilliseconds() > delay) // 23cps : max = 180cps @ 10
            {
                click();
                click_timer.restart();
            }
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        Sleep(10);
    }

    std::cout << "exited loop\n";
    return EXIT_SUCCESS;
}