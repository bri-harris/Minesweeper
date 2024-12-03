#include <iostream>
#include <fstream>
#include "TextureManager.h"
#include "Random.h"
#include "Board.h"
#include "Worker.h"
#include "Window.h"
using namespace Worker;
using namespace std;

int main() {
     Board board = CreateBoardFromFile("./boards/config.cfg");
     Window gameWindow = CreateWindowFromBoard(board);
     sf::RenderWindow window(sf::VideoMode(gameWindow._width, gameWindow._height), "SFML works!");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                float x = mousePosition.x;
                float y = mousePosition.y;

                if (gameWindow._happy.getGlobalBounds().contains(x, y)){
                    board.ResetBoard();
                    board.PlantRandMines(GetMineNumFromConfig("./boards/config.cfg"));

                }
                if (gameWindow._test1.getGlobalBounds().contains(x,y)) {
                   SetupTestBoard(board,"./boards/testboard1.brd");
                }
                if (gameWindow._test2.getGlobalBounds().contains(x,y)) {
                    SetupTestBoard(board,"./boards/testboard2.brd");
                }
                if (gameWindow._test3.getGlobalBounds().contains(x,y)) {
                    SetupTestBoard(board,"./boards/testboard3.brd");
                }
                if (gameWindow._debug.getGlobalBounds().contains(x, y)){
                    // cout << "Debug Position: (" << x << ", " <<y << ")" << endl;
                    board.SetDebugStatus();
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    board.LeftMousePress(x, y);
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    board.RightMousePress(x, y);
                    // if(board.RightMousePress(x, y)) {
                    //     DrawDigits(board,window);
                    //     // cout << board.GetFlagsAllowed();
                    // }


                }

            }
        }
        window.clear();

        BuildBoard(board,window);
        DrawDigits(board,window);

        if (board.GetDebugStatus()) {
            DebugToggle(board.GetTileLayout(),window);
        }
        DrawMenu(gameWindow,window);
        window.display();
    }
    return 0;
}
