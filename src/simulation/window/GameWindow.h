#pragma once

#include <SDL.h>
#undef main
#include "../../interface/window/Window.h"

namespace simulation::window
{

    class GameWindow : public interface::window::Window
    {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        inline explicit GameWindow(const std::string &title, int width, int height)
            : Window(title, width, height)
        {
            Init();
        }

        inline SDL_Renderer *GetRenderer()
        {
            return renderer;
        }

        ~GameWindow() override;

        void Init() override;

        void Update() override;

        void Render() override;

        void Reset() override;

        void EndFrame() override;

        void BeginFrame() override;

        void Close() override;

        void Show() override;

        void HandleInput() override;
    };

}