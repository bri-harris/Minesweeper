#include "Window.h"
#include "Worker.h"
#include <iostream>

Window::Window(Board& board): _board(board) {
    _height = board.GetRows() * 32 + 100;
    _width = board.GetColumns() * 32;

    _digitsX = 18;
    _digitsY = board.GetRows() * 32;

    _smileX = _width / 2 - 32;
    _smileY = board.GetRows() * 32;

    _happy.setTexture(TextureManager::GetTexture("face_happy"));
    _lose.setTexture(TextureManager::GetTexture("face_lose"));
    _win.setTexture(TextureManager::GetTexture("face_win"));

    _debug.setTexture(TextureManager::GetTexture("debug"));
    _test1.setTexture(TextureManager::GetTexture("test_1"));
    _test2.setTexture(TextureManager::GetTexture("test_2"));
    _test3.setTexture(TextureManager::GetTexture("test_3"));

    _tensDigit.setTexture(TextureManager::GetTexture("digits"));
    _onesDigit.setTexture(TextureManager::GetTexture("digits"));

}

void Window::SetDigits(Board& board, float x, float y) {
    int flagsAllowed = board.GetFlagsAllowed();
    int tensPlace = flagsAllowed / 10;
    int onesPlace = flagsAllowed % 10;
    // cout << "Tens Place: " << tensPlace << endl;
    // cout << "Ones Place: " << onesPlace << endl;


    _tensDigit.setTextureRect(sf::IntRect(tensPlace*21, 0, 21, 32));
    _tensDigit.setPosition(x,y);

    _onesDigit.setTextureRect(sf::IntRect(onesPlace*21, 0, 21, 32));
    _onesDigit.setPosition(x+21,y);


}
void Window::SetPosition(float x, float y) {
    _happy.setPosition(x, y);

    _lose.setPosition(x, y);
    _win.setPosition(x, y);

    x+= 4*32;
    _debug.setPosition(x, y);
    x+=2*32;
    _test1.setPosition(x, y);
    x+=2*32;
    _test2.setPosition(x, y);
    x+=2*32;
    _test3.setPosition(x, y);
}








