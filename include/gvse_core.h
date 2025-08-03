///
/// @file GVSE_CORE/GVSECore.h
///
/// This file contains the GVSECore class definition.
///

#ifndef GVSE_CORE
#define GVSE_CORE

#include <SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>        // SetProcessDPIAware()
#endif

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

         SDL_Window* m_window;
         SDL_GLContext m_gl_context;
         float m_main_scale;
         const char* m_glsl_version;
         ImGuiIO* m_io;

         bool setup_sdl();
         bool setup_imgui();
         void run();

         /// Disallow the copy constructor.
         GVSECore(const GVSECore&) = delete;

         /// Disallow the assignment operator.
         GVSECore& operator=(const GVSECore&) = delete;
   };

}

#endif // GVSE_CORE
