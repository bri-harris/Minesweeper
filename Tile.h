#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"
using std::vector;

class Tile {
    sf::Sprite _hidden, _revealed, _mine, _flag;
    bool _isRevealed= false;
    bool _hasMine= false;
    bool _isFlagged = false;

    vector<Tile*> _adjacentTiles;

public:
    Tile();

    sf::Sprite& GetTileSprite();
    sf::Sprite& GetMineSprite();
    sf::Sprite& GetFlagSprite();
    void SetMine();

    bool HasMine();
    bool isRevealed();
    bool isFlagged();

    bool Contains(float x, float y);
    bool ContainsFlag(float x, float y);

    void SetPosition(float x, float y);

    void Flag();
    void Reveal();
};
