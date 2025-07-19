///
/// @file GVSE_CORE/GVSECore.h
///
/// This file contains the GVSECore class definition.
///

#ifndef GVSE_CORE
#define GVSE_CORE

namespace gvse
{

/// class description.
class GVSECore
{
public:
  /// Creates an object.
  /// 
  /// @return  Pointer to the object if successful; Otherwise nullptr
  static GVSECore* create();

  /// Destroy an object.
  /// 
  /// @param[in] p_obj   Pointer to object
  static void destroy(GVSECore*& p_obj);

  /// Constructor.
  GVSECore();

  ///Destructor.
  virtual ~GVSECore();

  /// Checks if the object has been initialized.
  ///
  /// @return true if the object is initialized.
  bool is_initialized();

private:
  struct GVSECore_impl;    // Private struct
  GVSECore_impl* mp_impl;  // Pointer to private struct

  /// Disallow the copy constructor.
  GVSECore(const GVSECore&) = delete;

  /// Disallow the assignment operator.
  GVSECore& operator=(const GVSECore&) = delete;
};

}

#endif // GVSE_CORE
