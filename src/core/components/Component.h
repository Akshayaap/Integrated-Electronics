#pragma once

#include "../../interface/gfx/Drawable.h"


namespace core::components {

    class Component : public interface::gfx::Drawable {
    protected:
        interface::gfx::Image *image = nullptr;
        lib::math::Vec2 pos;
        lib::math::Vec2 size;
    public:
        inline explicit Component(interface::gfx::Renderer *renderer)
                : Drawable(renderer), pos(0, 0), size(0, 0) {

        };

        inline explicit Component(interface::gfx::Renderer *renderer, const lib::math::Vec2 &pos,
                                  const lib::math::Vec2 &size)
                : Drawable(renderer), pos(pos), size(size) {

        }

        ~Component() override;

        inline void SetImage(interface::gfx::Image *image) {
            this->image = image;
        }

        void Render() override;

        virtual void Update();

    };
}