///
/// @file GVSE_WINDOW_MANAGER/GVSEWindowManager.h
///
/// This file contains the GVSEWindowManager class definition.
///

#ifndef GVSE_WINDOW_MANAGER
#define GVSE_WINDOW_MANAGER

namespace gvse
{

/// class description.
class GVSEWindowManager
{
public:
  /// Creates an object.
  /// 
  /// @return  Pointer to the object if successful; Otherwise nullptr
  static GVSEWindowManager* create();

  /// Destroy an object.
  /// 
  /// @param[in] p_obj   Pointer to object
  static void destroy(GVSEWindowManager*& p_obj);

  /// Constructor.
  GVSEWindowManager();

  ///Destructor.
  virtual ~GVSEWindowManager();

  /// Checks if the object has been initialized.
  ///
  /// @return true if the object is initialized.
  bool is_initialized();

private:
  struct GVSEWindowManager_impl;    // Private struct
  GVSEWindowManager_impl* mp_impl;  // Pointer to private struct

  /// Disallow the copy constructor.
  GVSEWindowManager(const GVSEWindowManager&) = delete;

  /// Disallow the assignment operator.
  GVSEWindowManager& operator=(const GVSEWindowManager&) = delete;
};

}

#endif // GVSE_WINDOW_MANAGER
