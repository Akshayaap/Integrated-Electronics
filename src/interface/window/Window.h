#pragma once

#include <memory>
#include <string>
#include "../io/InputBridge.h"
#include "../gfx/Renderer.h"

namespace interface::window {

    class Window {
    protected:
        int height = 0;
        int width = 0;
        std::string title = "";
        interface::io::InputBridge *input = nullptr;
        interface::gfx::Renderer *renderer = nullptr;
    public:
        inline Window(const std::string &title, int width, int height)
                : title(title), width(width), height(height) {}

        virtual ~Window();

        inline int GetWidth() const {
            return width;
        }

    public:
        inline void SetWidth(int width) {
            this->width = width;
        }

        inline int GetHeight() const {
            return this->height;
        }

        inline void SetHeight(int height) {
            this->height = height;
        }

        inline const std::string &GetTitle() const {
            return this->title;
        }

        inline void SetTitle(const std::string &title) {
            this->title = title;
        }

        inline void SetInputBridge(interface::io::InputBridge *input) {
            this->input = input;
        }

        virtual void Init();

        virtual void Update();

        virtual void Render();

        virtual void Reset();

        virtual void EndFrame();

        virtual void BeginFrame();

        virtual void Close();

        virtual void Show();

        virtual void HandleInput();
    };
}


