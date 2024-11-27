#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string>
using std::unordered_map;
using std::string;


class TextureManager {
    static unordered_map<string, sf::Texture> textures;
    static void LoadTexture(string fileName); //LoadTexture("space")
    static string imagesDirectory;

public:
    static sf::Texture& GetTexture(string textureName);
    // static void SetImagesDirectory(string directoryPath);
    static void Clear(); //call this to clear all loaded textures
};


