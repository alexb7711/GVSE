///
/// @file GVSE_WINDOW/GVSEWindow.cpp
///
/// This file contains the GVSEWindow class definition.
///

#include <GVSE_WINDOW/GVSEWindow.h>
#include <new>

namespace gvse {

struct GVSEWindow::GVSEWindow_impl {
  bool m_initialized;

  GVSEWindow_impl() : m_initialized(false) {}
};

//==============================================================================
GVSEWindow *GVSEWindow::create() {
  GVSEWindow *p_obj = new (std::nothrow) GVSEWindow;

  if ((p_obj != nullptr) && (!p_obj->is_initialized())) {
    delete p_obj;
    p_obj = nullptr;
  }

  return p_obj;
}

//==============================================================================
void GVSEWindow::destroy(GVSEWindow *&p_obj) {
  delete p_obj;
  p_obj = nullptr;
}

//==============================================================================
GVSEWindow::GVSEWindow() : mp_impl(new GVSEWindow_impl) {}

//==============================================================================
GVSEWindow::~GVSEWindow() { delete mp_impl; }

//==============================================================================
bool GVSEWindow::is_initialized() {
  return (mp_impl != 0) && (mp_impl->m_initialized);
}

} // namespace gvse
