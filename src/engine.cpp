// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#include <thread>
#include <chrono>
#include <SDL.h>
#include "engine.hpp"
#include "logger.hpp"

namespace HPP {

Engine::Engine() {
    // Initialize the engine
}

Engine::~Engine() {
    // Clean up the engine
}

void Engine::run() {
    // Run the engine
    Logger::GetInstance().log("Engine is running");

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* Window{SDL_CreateWindow("Hello Window", 0, 0, 800, 300, 0)};
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
    }
}

}  // namespace HPP
