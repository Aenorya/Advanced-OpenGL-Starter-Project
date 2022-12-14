#ifndef ASSETS_H
#define ASSETS_H

#include <map>
#include <string>

#include <glew.h>

#include "Texture.h"
#include "../Shader.h"
#include "../ShaderProgram.h"
#include "TextureKtx.h"

// A static singleton Assets class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no
// public constructor is defined.
class Assets {
public:
    // Resource storage
    static std::map<std::string, Texture2D> textures;
    static std::map<std::string, TextureKtx> ktxTextures;


    // Loads (and generates) a texture from file
    static Texture2D loadTexture(const std::string &file, const std::string &name);

    // Retrieves a stored texture
    static Texture2D &getTexture(const std::string &name);

    // Loads (and generates) a texture from file
    static TextureKtx loadTextureKtx(const std::string &file, const std::string &name);

    // Retrieves a stored texture
    static TextureKtx &getTextureKtx(const std::string &name);

    // Properly de-allocates all loaded resources
    static void clear();

private:
    // Private constructor, that is we do not want any actual resource manager objects.
    // Its members and functions should be publicly available (static).
    Assets() {}

    // Loads a single texture from file
    static Texture2D loadTextureFromFile(const std::string &file);
};

#endif