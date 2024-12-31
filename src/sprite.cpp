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

void Sprite::Load(SDL_Renderer* renderer) {
    if (std::filesystem::exists(m_path) == false) {
        Logger::GetInstance().error("Sprite file not found: " + m_path);
        return;
    }
    m_texture = IMG_LoadTexture(renderer, m_path.c_str());
    if (m_texture == nullptr) {
        Logger::GetInstance().error("Failed to load texture: " + m_path);
    }
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_texture_size.width, &m_texture_size.height);
    if (m_texture_size.height % m_size.height != 0 || m_texture_size.width % m_size.width != 0) {
        Logger::GetInstance().error("Invalid sprite size: " + m_path);
    }
    UpdateFrames(m_start_frame, m_end_frame);
}

void Sprite::UpdateFrames(size_t start_frame, size_t end_frame) {
    // Update the frames of the sprite
    m_vec_frames.clear();
    for (int y = 0; y < m_texture_size.height; y += m_size.height) {
        for (int x = 0; x < m_texture_size.width; x += m_size.width) {
            size_t frame = y / m_size.height * m_texture_size.width / m_size.width + x / m_size.width;
            if (frame < start_frame || frame > end_frame) {
                continue;
            }
            SDL_Rect rect = {x, y, m_size.width, m_size.height};
            m_vec_frames.push_back(rect);
        }
    }
    m_total_frames = m_vec_frames.size();
}

void Sprite::Update(float delta) {
    // Update the sprite
    m_time += delta;
    m_time = std::fmod(m_time, m_total_frames/m_playback_speed);
    m_current_frame = static_cast<size_t>(std::fmod(m_time * m_playback_speed, m_total_frames));
}

void Sprite::Render(SDL_Renderer* renderer) {
    // Render the sprite
    SDL_Rect srcrect = m_vec_frames[m_current_frame];
    SDL_Rect dstrect = {m_position.x, m_position.y, (int)(m_size.width*m_ratio), (int)(m_size.height*m_ratio)};
    SDL_RenderCopyEx(renderer, m_texture, &srcrect, &dstrect, 0, nullptr, (SDL_RendererFlip)m_flip);
}

}  // namespace Patungkuonu
