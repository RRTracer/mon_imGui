// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <cmath>
#include <stdio.h>
#include <SDL.h>
#include "stb_image.h"

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

// Function to create texture
GLuint create_texture(const char* image_path, int* width, int* height) {
    unsigned char* data = stbi_load(image_path, width, height, nullptr, 4); // Charge l'image avec alpha
    if (!data) {
        printf("Failed to load texture: %s\n", stbi_failure_reason());
        return 0;
    }

    GLuint texture_id;
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // Remplir la texture avec l'image chargée
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data); // Libérer la mémoire de l'image
    return texture_id;
}

// Main code
int main(int, char**) {
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    const char* glsl_version = "#version 100"; // GL ES 2.0 + GLSL 100
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    const char* glsl_version = "#version 150"; // GL 3.2 Core + GLSL 150
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    const char* glsl_version = "#version 130"; // GL 3.0 + GLSL 130
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);

    if (window == nullptr) {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return -1;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark(); // Utilisez un style par défaut

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Tool activation flags
    bool my_tool_active = true;
    bool my_tool = true;
    const char* image_path = "chat.jpeg"; // Chemin vers votre image
    int image_width = 0;        // Largeur de l'image
    int image_height = 0;       // Hauteur de l'image
    GLuint texture_id = create_texture(image_path, &image_width, &image_height); // Créer une texture à partir de l'image
    bool show_image = false; // Contrôle pour afficher l'image

    // Variables for resource usage
    int clicked = 0;

    // Main loop
    bool done = false;
#ifdef __EMSCRIPTEN__
    ImGui::GetIO().IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!done)
#endif
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event); // Traitez les événements SDL ici
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }

        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Main GUI code
        if (my_tool_active) {
            ImGui::Begin("Linear Signal Color Tools", &my_tool_active);

            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("Analyseur Réseau")) {
                    if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            // Generate samples and plot them
            float samples[1000];
            for (int n = 0; n < 1000; n++)
                samples[n] = sinf(n * 0.4f + ImGui::GetTime() * 1.8f);
            ImGui::PlotLines("Test de 1000", samples, 1000);

            float samples_2[100];
            for (int n = 0; n < 100; n++)
                samples_2[n] = sinf(n * 0.4f + ImGui::GetTime() * 1.8f);
            ImGui::PlotLines("Test de 100", samples_2, 100);

            float samples_3[10];
            for (int n = 0; n < 10; n++)
                samples_3[n] = cos(n * 0.3f + ImGui::GetTime() * 1.5f);
            ImGui::PlotLines("Test de 10", samples_3, 10);

            if (ImGui::Button("Open check box tool")) {
                my_tool = true;
            }
            ImGui::End();
        }

        if (my_tool) {
            ImGui::Begin("Linear Signal Color Tools", &my_tool);

            const char* items[] = { "Option A", "Option B", "Option C" };
            static bool selected_items[IM_ARRAYSIZE(items)] = { false, false, false }; // Checkboxes for each item

            for (int i = 0; i < IM_ARRAYSIZE(items); i++) {
                ImGui::Checkbox(items[i], &selected_items[i]); // Show the checkbox

                if (selected_items[i]) {
                    ImGui::SameLine();
                    if (ImGui::Button("Désélectionner")) {
                        selected_items[i] = false; // Deselect the checkbox
                    }
                }
            }

            // Ajout du bouton pour afficher/masquer l'image
            if (ImGui::Button("Toggle Image")) {
                show_image = !show_image; // Inverser l'état d'affichage de l'image
            }

            // Afficher l'image si show_image est vrai
            if (show_image && texture_id) {
                ImGui::Text("Image:");
                ImGui::Image((void*)(intptr_t)texture_id, ImVec2(image_width, image_height)); // Afficher la texture
            }

            if (ImGui::Button("Close Window"))
                clicked++;

            if (clicked & 1) {
                ImGui::SameLine();
                ImGui::OpenPopup("Delete?");
                clicked = 0;
            }

            if (ImGui::BeginPopupModal("Delete?", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
                ImGui::Text("You are going to close the window! Are you sure?");
                ImGui::Separator();

                static bool dont_ask_me_next_time = false;
                ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
                ImGui::Checkbox("Don't ask me next time", &dont_ask_me_next_time);
                ImGui::PopStyleVar();

                if (ImGui::Button("OK", ImVec2(120, 0))) {
                    ImGui::Text("Merci d'avoir utilisé mon logiciel");
                    my_tool = false;
                    ImGui::CloseCurrentPopup();
                }
                ImGui::SetItemDefaultFocus();
                ImGui::SameLine();

                if (ImGui::Button("Cancel", ImVec2(120, 0))) {
                    my_tool = false;
                    ImGui::CloseCurrentPopup();
                }

                ImGui::EndPopup();
            }
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
