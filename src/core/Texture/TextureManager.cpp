#include "TextureManager.h"
#include <iostream>

TextureManager& TextureManager::getInstance() {
	static TextureManager instance;
	return instance;
}

sf::Texture& TextureManager::getTexture(const std::string& seedName) {
	auto& textures = this->textures;
	auto it = textures.find(seedName);
	if (it != textures.end()) return it->second;

	sf::Texture texture;
	std::string path = "res/img/" + seedName + ".png";


	if (!texture.loadFromFile(path)) {
		std::cerr << "Erreur chargement image : " << path << "\n";
	}

	textures[seedName] = std::move(texture);
	return textures[seedName];
}
