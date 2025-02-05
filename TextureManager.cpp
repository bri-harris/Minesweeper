#include "TextureManager.h"

//redeclare the variable so this file knows it exists and use it
unordered_map<string, sf::Texture> TextureManager::textures;
string TextureManager::imagesDirectory;

void TextureManager::LoadTexture(string fileName) {
    string path = "images/";
    path += fileName + ".png";
    textures[fileName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
    //if the texture doesnt exist, load it first, then return it?
    if (textures.find(textureName) == textures.end())
        LoadTexture(textureName);

    return textures[textureName];
}
// void TextureManager::SetImagesDirectory(string directoryPath) {
//     imagesDirectory = directoryPath;
// }

void TextureManager::Clear() {
    textures.clear(); //get rid of all stored objects
}
