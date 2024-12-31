// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <string>
#include <memory>
#include "engine.hpp"  // NOLINT
#include "sprite.hpp"  // NOLINT
#include "logger.hpp"  // NOLINT

namespace Patungkuonu {  // namespace HPP

Engine::Engine(const Setting& setting) {
    // Initialize the engine
    m_setting = setting;
    Initialize();
}

Engine::~Engine() {
    // Clean up the engine
    Cleanup();
}

bool Engine::Initialize() {
    // Initialize the engine
    Logger::GetInstance().info("Engine is initialized");
    bool success = true;
    m_event = std::make_unique<SDL_Event>();
    IMG_Init(IMG_INIT_PNG);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        Logger::GetInstance().error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        success = false;
    } else {
        m_window = SDL_CreateWindow(m_setting.GetWindowName().c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    m_setting.GetWindowWidth(),
                                    m_setting.GetWindowHeight(),
                                    SDL_WINDOW_SHOWN);
        if (m_window == nullptr) {
            Logger::GetInstance().error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
            success = false;
        } else {
            Logger::GetInstance().info("Window created successfully");
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        }
    }
    return success;
}

void Engine::Cleanup() {
    // Clean up the engine
    m_event.reset();
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    IMG_Quit();
    SDL_Quit();
    Logger::GetInstance().info("Engine is cleaned up");
}

void Engine::AddObject(GameObject* object) {
    // Add a sprite to the engine
    object->GetSprite()->Load(m_renderer);
    m_objects.push_back(object);
}

void Engine::Run() {
    // Run the engine
    Logger::GetInstance().info("Engine is running");
    bool quit = false;
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time = 0;
    float delta = 0.0f;

    while (!quit) {
        current_time = SDL_GetTicks();
        delta = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        while (SDL_PollEvent(m_event.get()) != 0) {
            if (m_event->type == SDL_QUIT) {
                quit = true;
            }
            for (GameObject* object : m_objects) {
                object->Update(m_event.get());
            }
        }
        SDL_RenderClear(m_renderer);
        // Draw the sprites
        for (GameObject* object : m_objects) {
            object->GetSprite()->Update(delta);
            object->GetSprite()->Render(m_renderer);
        }
        SDL_RenderPresent(m_renderer);
    }
}

}  // namespace Patungkuonu
