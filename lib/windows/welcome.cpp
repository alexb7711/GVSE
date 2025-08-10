///
/// @file GVSE_WINDOW/WelcomeWindow.cpp
///
/// This file contains the WelcomeWindow class definition.
///

#include <gvse_window.h>
#include <welcome.h>

#include <cstdio>
#include <fmt/format.h>
#include <string>

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

  ImGui::Begin("GVSE");

  ImGui::Button("Data Table");
  ImGui::SameLine();
  ImGui::Button("2D View Model");
  ImGui::SameLine();
  ImGui::Button("Plots");

  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
              1000.0f / winfo->io->Framerate,
              winfo->io->Framerate);
  ImGui::End();

  return true;
}

//==============================================================================
WelcomeWindow::~WelcomeWindow() {}

} // namespace gvse
