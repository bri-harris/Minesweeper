#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"
using std::vector;

class Tile {
    sf::Sprite _hidden, _revealed, _mine, _flag, _number;
    bool _isRevealed= false;
    bool _hasMine= false;
    bool _isFlagged = false;
    bool _hasNumber = false;

    vector<Tile*> _adjacentTiles;

public:
    Tile();

    sf::Sprite& GetTileSprite();
    sf::Sprite& GetMineSprite();
    sf::Sprite& GetFlagSprite();
    sf::Sprite& GetNumberSprite();

    bool HasNumber();
    bool HasMine();
    bool isRevealed();
    bool isFlagged();
    bool Contains(float x, float y);
    bool ContainsFlag(float x, float y);

    void SetMine();
    void SetNumber(int number);
    void SetPosition(float x, float y);
    void Flag();
    void Reveal();

    void SetAdjacent(Tile* tile);
    int GetNumNeighbors();
    void RevealEligibleNeighbors();
};
