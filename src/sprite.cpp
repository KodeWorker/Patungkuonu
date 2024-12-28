// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <filesystem>  // NOLINT
#include <cmath>
#include <SDL_image.h>
#include "sprite.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

namespace Patungkuonu {  // namespace Patungkuonu

Sprite::Sprite() {
}

Sprite::~Sprite() {
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

void Sprite::Attach(SDL_Renderer* renderer) {
    // Attach SDL Renderer and load the texture
    if (renderer == nullptr) {
        Logger::GetInstance().error("Renderer is null");
    }
    m_renderer = renderer;

    if (std::filesystem::exists(m_path) == false) {
        Logger::GetInstance().error("Sprite file not found: " + m_path);
        return;
    }
    m_texture = IMG_LoadTexture(m_renderer, m_path.c_str());
    if (m_texture == nullptr) {
        Logger::GetInstance().error("Failed to load texture: " + m_path);
    }
    int textureWidth, textureHeight;
    SDL_QueryTexture(m_texture, nullptr, nullptr, &textureWidth, &textureHeight);
    if (textureHeight % m_height != 0 || textureWidth % m_width != 0) {
        Logger::GetInstance().error("Invalid sprite size: " + m_path);
    }
    for (int y = 0; y < textureHeight; y += m_height) {
        for (int x = 0; x < textureWidth; x += m_width) {
            SDL_Rect rect = {x, y, m_width, m_height};
            m_frames.push_back(rect);
        }
    }
    m_total_frames = m_frames.size();
}

void Sprite::Update(float delta) {
    // Update the sprite
    m_time += delta;
    m_time = std::fmod(m_time, m_total_frames/m_playback_speed);
    m_current_frame = static_cast<int>(std::fmod(m_time * m_playback_speed, m_total_frames));
}

void Sprite::Render() {
    // Render the sprite
    SDL_Rect srcrect = m_frames[m_current_frame];
    SDL_Rect dstrect = {m_x, m_y, m_width, m_height};
    SDL_RenderCopy(m_renderer, m_texture, &srcrect, &dstrect);
}

}  // namespace Patungkuonu
