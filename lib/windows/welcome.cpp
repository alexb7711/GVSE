///
/// @file GVSE_WINDOW/WelcomeWindow.cpp
///
/// This file contains the WelcomeWindow class definition.
///

#include <gvse_window.h>
#include <new>
#include <welcome.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"

namespace gvse {

//==============================================================================
WelcomeWindow::WelcomeWindow() {}

//==============================================================================
bool
WelcomeWindow::execute_once(WinInfo* winfo)
{

  // Our state
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  /// 2. Show a simple window that we create ourselves. We use a Begin/End
  /// pair / to create a named window.
  {
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Hello, world!"); // Create a window called "Hello, world !"
    // and append into it.

    ImGui::Text("This is some useful text."); // Display some text (you can
    // use a format strings too)
    ImGui::Checkbox("Another Window", &show_another_window);

    ImGui::SliderFloat("float",
                       &f,
                       0.0f,
                       1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
    ImGui::ColorEdit3(
      "clear color",
      (float*)&clear_color); // Edit 3 floats representing a color

    if (ImGui::Button("Button")) // Buttons return true when clicked (most
                                 // widgets return true when edited/activated)
      counter++;

    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / winfo->io->Framerate,
                winfo->io->Framerate);
    ImGui::End();
  }

  return true;
}

//==============================================================================
WelcomeWindow::~WelcomeWindow() {}

} // namespace gvse
