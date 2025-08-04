///
/// @file GVSE_WINDOW_MANAGER/GVSEWindowManager.h
///
/// This file contains the GVSEWindowManager class definition.
///

#ifndef GVSE_WINDOW_MANAGER
#define GVSE_WINDOW_MANAGER

#include <gvse_window.h>
#include <vector>

namespace gvse {

/// class description.
class GVSEWindowManager
{
public:
  /// Constructor.
  GVSEWindowManager();

  /// Destructor.
  ~GVSEWindowManager();

  /// Add window to be processed
  bool subscribe(GVSEWindow* w);

  /// Run all windows once
  bool execute();

private:
  std::vector<GVSEWindow*> m_windows;
};

} // namespace gvse

#endif // GVSE_WINDOW_MANAGER
