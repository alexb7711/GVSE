///
/// @file GVSE_DATA_MANAGER/GVSEDataManager.h
///
/// This file contains the GVSEDataManager class definition.
///

#ifndef GVSE_DATA_MANAGER
#define GVSE_DATA_MANAGER

namespace gvse
{

/// class description.
class GVSEDataManager
{
public:
  /// Creates an object.
  /// 
  /// @return  Pointer to the object if successful; Otherwise nullptr
  static GVSEDataManager* create();

  /// Destroy an object.
  /// 
  /// @param[in] p_obj   Pointer to object
  static void destroy(GVSEDataManager*& p_obj);

  /// Constructor.
  GVSEDataManager();

  ///Destructor.
  virtual ~GVSEDataManager();

  /// Checks if the object has been initialized.
  ///
  /// @return true if the object is initialized.
  bool is_initialized();

private:
  struct GVSEDataManager_impl;    // Private struct
  GVSEDataManager_impl* mp_impl;  // Pointer to private struct

  /// Disallow the copy constructor.
  GVSEDataManager(const GVSEDataManager&) = delete;

  /// Disallow the assignment operator.
  GVSEDataManager& operator=(const GVSEDataManager&) = delete;
};

}

#endif // GVSE_DATA_MANAGER
