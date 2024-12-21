// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include "engine.hpp"
#include "logger.hpp"

namespace Patungkuonu {  // namespace HPP

Engine::Engine() {
    // Initialize the engine
    Initialize();
}

Engine::~Engine() {
    // Clean up the engine
    Cleanup();
}

bool Engine::Initialize() {
    // Initialize the engine
    Logger::GetInstance().log("Engine is initialized");
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Logger::GetInstance().log("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        success = false;
    } else {
        m_window = SDL_CreateWindow(m_window_name.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    m_window_width,
                                    m_window_height,
                                    SDL_WINDOW_SHOWN);
        if (m_window == nullptr) {
            Logger::GetInstance().log("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
            success = false;
        } else {
            Logger::GetInstance().log("Window created successfully");
            m_surface = SDL_GetWindowSurface(m_window);
        }
    }
    return success;
}

void Engine::Cleanup() {
    // Clean up the engine
    SDL_FreeSurface(m_surface);
    m_surface = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
    SDL_Quit();
    Logger::GetInstance().log("Engine is cleaned up");
}

void Engine::run() {
    // Run the engine
    Logger::GetInstance().log("Engine is running");
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_FillRect(m_surface, nullptr, SDL_MapRGB(m_surface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(m_window);
    }
}

}  // namespace Patungkuonu
