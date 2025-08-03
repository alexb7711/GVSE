///
/// @file GVSE_WINDOW_MANAGER/GVSEWindowManager.cpp
///
/// This file contains the GVSEWindowManager class definition.
///

#include <new>
#include <GVSE_WINDOW_MANAGER/GVSEWindowManager.h>

namespace gvse
{

struct GVSEWindowManager::GVSEWindowManager_impl
{
  bool m_initialized;

  GVSEWindowManager_impl()
    : m_initialized(false)
  {}
};

//==============================================================================
GVSEWindowManager* GVSEWindowManager::create()
{
  GVSEWindowManager* p_obj = new(std::nothrow) GVSEWindowManager;

  if ((p_obj != nullptr) && (!p_obj->is_initialized()))
  {
    delete p_obj;
    p_obj = nullptr;
  }

  return p_obj;
}

//==============================================================================
void GVSEWindowManager::destroy(GVSEWindowManager*& p_obj)
{
  delete p_obj;
  p_obj = nullptr;
}

//==============================================================================
GVSEWindowManager::GVSEWindowManager()
  : mp_impl(new GVSEWindowManager_impl)
{
}

//==============================================================================
GVSEWindowManager::~GVSEWindowManager()
{
  delete mp_impl;
}

//==============================================================================
bool GVSEWindowManager::is_initialized()
{
  return (mp_impl != 0) && (mp_impl->m_initialized);
}

}

