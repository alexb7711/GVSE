///
/// @file GVSE_WINDOW_MANAGER/GVSEWindowManager.cpp
///
/// This file contains the GVSEWindowManager class definition.
///

#include <cstdio>
#include <gvse_window_manager.h>
#include <new>
#include <stdexcept>

namespace gvse {

//==============================================================================
GVSEWindowManager::GVSEWindowManager() {}

//==============================================================================
GVSEWindowManager::~GVSEWindowManager()
{
  // Delete the windows
  for (GVSEWindow* w : this->m_windows) {
    delete w;
  }
}

//==============================================================================
bool
GVSEWindowManager::subscribe(GVSEWindow* w)
{
  try {
    this->m_windows.push_back(w);
    return true;
  } catch (const std::exception& e) {
    std::printf("Unable to subscribe window.");
    std::printf("ERROR: %s", e.what());
    return false;
  }
}

//==============================================================================
bool
GVSEWindowManager::execute(WinInfo* winf)
{
  bool success = true;

  for (GVSEWindow* w : this->m_windows) {
    // Process current window
    success = w->execute_once(winf);

    // If the processed window fails
    if (!success) {
      break;
    }
  }

  return success;
}

} // namespace gvse
