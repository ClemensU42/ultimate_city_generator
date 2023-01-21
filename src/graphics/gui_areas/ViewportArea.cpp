//
// Created by Clemens on 21/01/2023.
//

#include "ViewportArea.h"
#include "imgui.h"

#include <glad/glad.h>
#include <iostream>

namespace GuiAreas {
    void ViewportArea::Initialize() {
        glGenFramebuffers(1, &this->fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, this->fbo);
        glGenTextures(1, &this->texture);
    }

    void ViewportArea::Render() {
        ImGui::Begin("Viewport");
        if(this->isDirty){
            this->isDirty = false;
            this->viewportWidth = ImGui::GetWindowContentRegionWidth();
            this->viewportHeight = ImGui::GetWindowContentRegionMax().y - 27;
            this->Clean();
        }

        BindFramebuffer();

        //TODO: render preview
        glClearColor(0.5f, 0.3f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        UnbindFramebuffer();

        ImGui::Image(
                    (ImTextureID) this->texture,
                    ImVec2(this->viewportWidth,this->viewportHeight),
                    ImVec2(0, 1),
                    ImVec2(1, 0));


        ImGui::End();
    }

    void ViewportArea::BindFramebuffer() const {
        glBindFramebuffer(GL_FRAMEBUFFER, this->fbo);
    }

    void ViewportArea::UnbindFramebuffer() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void ViewportArea::End() {
        glDeleteFramebuffers(1, &this->fbo);
        glDeleteTextures(1, &this->texture);
    }

    void ViewportArea::Clean() {
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->viewportWidth, this->viewportHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->texture, 0);
        glBindTexture(GL_TEXTURE_2D, 0);

        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
            std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
} // GuiAreas