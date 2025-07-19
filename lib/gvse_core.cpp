///
/// @file GVSE_CORE/GVSECore.cpp
///
/// This file contains the GVSECore class definition.
///

#include <new>
#include <gvse_core.h>

namespace gvse
{

struct GVSECore::GVSECore_impl
{
  bool m_initialized;

  GVSECore_impl()
    : m_initialized(false)
  {}
};

//==============================================================================
GVSECore* GVSECore::create()
{
  GVSECore* p_obj = new(std::nothrow) GVSECore;

  if ((p_obj != nullptr) && (!p_obj->is_initialized()))
  {
    delete p_obj;
    p_obj = nullptr;
  }

  return p_obj;
}

//==============================================================================
void GVSECore::destroy(GVSECore*& p_obj)
{
  delete p_obj;
  p_obj = nullptr;
}

//==============================================================================
GVSECore::GVSECore()
  : mp_impl(new GVSECore_impl)
{
}

//==============================================================================
GVSECore::~GVSECore()
{
  delete mp_impl;
}

//==============================================================================
bool GVSECore::is_initialized()
{
  return (mp_impl != 0) && (mp_impl->m_initialized);
}

}

