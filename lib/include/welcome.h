///
/// @file GVSE_WINDOW/WelcomeWindow.h
///
/// This file contains the WelcomeWindow class definition.
///

#ifndef WELCOME_WINDOW
#define WELCOME_WINDOW

#include <gvse_window.h>

namespace gvse {

/// class description.
class WelcomeWindow : public GVSEWindow
{
public:
  /// Constructor.
  WelcomeWindow();

  /// Run the window
  bool execute_once();

  /// Destructor.
  ~WelcomeWindow();

private:
  /// Flag to indicate whether the window is open or not
  bool m_is_open = false;

  /// Window size
  float m_width = 0.0;
  float m_height = 0.0;
};

} // namespace gvse

#endif // GVSE_WINDOW
