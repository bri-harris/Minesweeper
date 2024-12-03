#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Board.h"
#include "TextureManager.h"
using namespace std;

struct Window {
    Board _board;

    unsigned int _width,_height;
    unsigned int _digitsX, _digitsY;
    unsigned int _smileX, _smileY;

    bool _gameStatus = true;
    bool _hasWon = false;
    bool _hasLost = false;

    sf::Sprite _happy,  _lose,  _win,  _debug,  _test1,  _test2,  _test3;

    Window(Board& board);
    sf::Sprite& GetSprite();

    void SetPosition(float x, float y);


};
