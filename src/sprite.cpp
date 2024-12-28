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
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_texture_size.width, &m_texture_size.height);
    if (m_texture_size.height % m_size.height != 0 || m_texture_size.width % m_size.width != 0) {
        Logger::GetInstance().error("Invalid sprite size: " + m_path);
    }
    UpdateRange(m_start_frame, m_end_frame);
}

void Sprite::UpdateRange(int start_frame, int end_frame, SDL_RendererFlip flip) {
    // Update the range
    m_flip = flip;
    m_frames.clear();
    for (int y = 0; y < m_texture_size.height; y += m_size.height) {
        for (int x = 0; x < m_texture_size.width; x += m_size.width) {
            int frame = y / m_size.height * m_texture_size.width / m_size.width + x / m_size.width;
            if (frame < start_frame || frame > end_frame) {
                continue;
            }
            SDL_Rect rect = {x, y, m_size.width, m_size.height};
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
    SDL_Rect dstrect = {m_position.x, m_position.y, m_size.width, m_size.height};
    SDL_RenderCopyEx(m_renderer, m_texture, &srcrect, &dstrect, 0, nullptr, m_flip);
}

}  // namespace Patungkuonu
