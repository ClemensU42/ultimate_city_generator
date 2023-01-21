//
// Created by Clemens on 21/01/2023.
//

#ifndef ULTIMATE_CITY_GENERATOR_VIEWPORTAREA_H
#define ULTIMATE_CITY_GENERATOR_VIEWPORTAREA_H

#include <cstdint>

namespace GuiAreas {

    class ViewportArea {
    public:
        uint32_t fbo;
        uint32_t texture;
        int viewportWidth, viewportHeight;

        bool isDirty = true;

    public:
        void Initialize();
        void Render();
        void BindFramebuffer() const;
        static void UnbindFramebuffer();
        void End();
        void Clean();
    };

} // GuiAreas

#endif //ULTIMATE_CITY_GENERATOR_VIEWPORTAREA_H
