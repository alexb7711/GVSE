///
/// @file GVSE_WINDOW/GVSEWindow.h
///
/// This file contains the GVSEWindow class definition.
///

#ifndef GVSE_WINDOW
#define GVSE_WINDOW

#include "win_info.h"

namespace gvse {

/// class description.
class GVSEWindow
{
public:
  /// Constructor.
  GVSEWindow() = default;

  /// Run the window
  virtual bool execute_once(WinInfo* winfo) = 0;

  /// Destructor.
  ~GVSEWindow() = default;

private:
  /// Flag to indicate whether the window is open or not
  bool m_is_open = false;

  /// Window size
  float m_width = 0.0;
  float m_height = 0.0;
};

} // namespace gvse

#endif // GVSE_WINDOW
