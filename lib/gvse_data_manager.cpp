///
/// @file GVSE_DATA_MANAGER/GVSEDataManager.cpp
///
/// This file contains the GVSEDataManager class definition.
///

#include<new>
#include <gvse_data_manager.h>

namespace gvse
{

struct GVSEDataManager::GVSEDataManager_impl
{
  bool m_initialized;

  GVSEDataManager_impl()
    : m_initialized(false)
  {}
};

//==============================================================================
GVSEDataManager* GVSEDataManager::create()
{
  GVSEDataManager* p_obj = new(std::nothrow) GVSEDataManager;

  if ((p_obj != nullptr) && (!p_obj->is_initialized()))
  {
    delete p_obj;
    p_obj = nullptr;
  }

  return p_obj;
}

//==============================================================================
void GVSEDataManager::destroy(GVSEDataManager*& p_obj)
{
  delete p_obj;
  p_obj = nullptr;
}

//==============================================================================
GVSEDataManager::GVSEDataManager()
  : mp_impl(new GVSEDataManager_impl)
{
}

//==============================================================================
GVSEDataManager::~GVSEDataManager()
{
  delete mp_impl;
}

//==============================================================================
bool GVSEDataManager::is_initialized()
{
  return (mp_impl != nullptr) && (mp_impl->m_initialized);
}

}

