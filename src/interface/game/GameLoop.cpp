#pragma once

#include <chrono>

#include "GameLoop.h"

void GameLoop::Go() {
    int frames = 0;
    double unprocessedSeconds = 0;
    double previousTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    double secondsForEachTick = 1 / 60.0;

    int tickCount = 0; // RENDER COUNTER
    bool ticked = false;

    while (isRunning) {
        double currentTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        double passedTime = currentTime - previousTime;

        previousTime = currentTime;

        unprocessedSeconds = unprocessedSeconds + passedTime / 1000000000.0;

        int count = 0;
        while (unprocessedSeconds > secondsForEachTick) {
            Update();
            count++;
            unprocessedSeconds -= secondsForEachTick;

            ticked = true;
            tickCount++;

            if (tickCount % 60 == 0) {
                previousTime += 1;
                frames = 0;
            }
        }
        if (ticked) {
            Render();
            frames++;
            ticked = false;
        }
    }
}

void GameLoop::Render() {}

void GameLoop::Update() {}

void GameLoop::Init() {}

void GameLoop::Reset() {}