#include "Tile.h"

Tile::Tile() {
    _revealed.setTexture(TextureManager::GetTexture("tile_revealed"));
    _flag.setTexture(TextureManager::GetTexture("flag"));
    _hidden.setTexture(TextureManager::GetTexture("tile_hidden"));

}

void Tile::SetMine() {
    _hasMine = true;
    _mine.setTexture(TextureManager::GetTexture("mine"));
}

void Tile::SetNumber(int number) {

}

sf::Sprite& Tile::GetTileSprite() {
        if (_isRevealed)
            return _revealed;

        return _hidden;
}
sf::Sprite& Tile::GetMineSprite() {
    if (_isRevealed)
        return _mine;
    return _hidden;
}
sf::Sprite& Tile::GetFlagSprite() {
    return _flag;
}

bool Tile::HasMine() {
    return _hasMine;
}
bool Tile::isRevealed() {
    return _isRevealed;
}
bool Tile::isFlagged() {
    return _isFlagged;
}

bool Tile::Contains(float x, float y) {
    return _revealed.getGlobalBounds().contains(x, y);
}
bool Tile::ContainsFlag(float x, float y) {
    return _flag.getGlobalBounds().contains(x, y);
}

void Tile::SetPosition(float x, float y) {
    _revealed.setPosition(x, y);
    _hidden.setPosition(x, y);
    if(_hasMine) _mine.setPosition(x,y);
    _flag.setPosition(x,y);
}

void Tile::Flag() {
    _isFlagged = !_isFlagged;
}
void Tile::Reveal() {
    if(!_isRevealed && !_isFlagged) _isRevealed = true;;
}




