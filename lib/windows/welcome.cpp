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
WelcomeWindow::execute_once()
{

  // Our state
  bool show_demo_window = true;

  // 1. Show the big demo window (Most of the sample code is in
  // ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear
  // ImGui!).
  if (show_demo_window)
    ImGui::ShowDemoWindow(&show_demo_window);

  return true;
}

//==============================================================================
WelcomeWindow::~WelcomeWindow() {}

} // namespace gvse
