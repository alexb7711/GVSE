///
/// @file GVSE_CORE/GVSECore.cpp
///
/// This file contains the GVSECore class definition.
///

#include <new>

#include <gvse_core.h>
#include <welcome.h>

namespace gvse {

struct GVSECore::GVSECore_impl
{
  bool m_initialized;

  GVSECore_impl()
    : m_initialized(false)
  {
  }
};

//==============================================================================
GVSECore*
GVSECore::create()
{
  GVSECore* p_obj = new (std::nothrow) GVSECore;

  if ((p_obj != nullptr) && (!p_obj->is_initialized())) {
    delete p_obj;
    p_obj = nullptr;
  }

  return p_obj;
}

//==============================================================================
void
GVSECore::destroy(GVSECore*& p_obj)
{
  delete p_obj;
  p_obj = nullptr;
}

//==============================================================================
GVSECore::GVSECore()
  : mp_impl(new GVSECore_impl)
{
  this->setup_sdl();
  this->setup_imgui();

  // FIXME: Subscribe the windows
  this->m_wm.subscribe(new WelcomeWindow());

  this->run();
  return;
}

//==============================================================================
GVSECore::~GVSECore()
{
  delete mp_impl;
}

//==============================================================================
bool
GVSECore::is_initialized()
{
  return (mp_impl != 0) && (mp_impl->m_initialized);
}

//==============================================================================
bool
GVSECore::setup_sdl()
{
  // Setup SDL
#ifdef _WIN32
  ::SetProcessDPIAware();
#endif
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) !=
      0) {
    printf("Error: %s\n", SDL_GetError());
    return false;
  }

  // GL 3.0 + GLSL 130
  m_glsl_version = "#version 130";
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
  SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

  // Create window with graphics context
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_WindowFlags window_flags =
    (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE |
                      SDL_WINDOW_ALLOW_HIGHDPI);
  this->m_window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    (int)(1280 * this->m_main_scale),
                                    (int)(720 * this->m_main_scale),
                                    window_flags);
  if (this->m_window == nullptr) {
    printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
    return false;
  }

  this->m_gl_context = SDL_GL_CreateContext(this->m_window);
  if (this->m_gl_context == nullptr) {
    printf("Error: SDL_GL_CreateContext(): %s\n", SDL_GetError());
    return false;
  }

  SDL_GL_MakeCurrent(this->m_window, this->m_gl_context);
  SDL_GL_SetSwapInterval(1); // Enable vsync

  return true;
}

//==============================================================================
bool
GVSECore::setup_imgui()
{
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  this->m_main_scale = ImGui_ImplSDL2_GetContentScaleForDisplay(0);
  this->m_io = &ImGui::GetIO();
  (void)this->m_io;
  this->m_io->ConfigFlags |=
    ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  this->m_io->ConfigFlags |=
    ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsLight();

  // Setup scaling
  ImGuiStyle& style = ImGui::GetStyle();
  style.ScaleAllSizes(
    this->m_main_scale); // Bake a fixed style scale. (until we have a solution
                         // for dynamic style scaling, changing this requires
                         // resetting Style + calling this again)
  style.FontScaleDpi =
    this->m_main_scale; // Set initial font scale. (using
                        // io.ConfigDpiScaleFonts=true makes this unnecessary.
                        // We leave both here for documentation purpose)

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForOpenGL(this->m_window, this->m_gl_context);
  ImGui_ImplOpenGL3_Init(this->m_glsl_version);

  // Load Fonts
  style.FontSizeBase = 20.0f;
  this->m_io->Fonts->AddFontDefault();

  return true;
}

void
GVSECore::run()
{
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Main loop
  bool done = false;
  while (!done) {
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to
    // tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to
    // your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input
    // data to your main application, or clear/overwrite your copy of the
    // keyboard data. Generally you may always pass all inputs to dear imgui,
    // and hide them from your application based on those two flags.
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT)
        done = true;
      if (event.type == SDL_WINDOWEVENT &&
          event.window.event == SDL_WINDOWEVENT_CLOSE &&
          event.window.windowID == SDL_GetWindowID(this->m_window))
        done = true;
    }
    if (SDL_GetWindowFlags(this->m_window) & SDL_WINDOW_MINIMIZED) {
      SDL_Delay(10);
      continue;
    }

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Process windows
    this->m_wm.execute();

    //// 2. Show a simple window that we create ourselves. We use a Begin/End
    /// pair / to create a named window.
    //{
    //  static float f = 0.0f;
    //  static int counter = 0;

    //  ImGui::Begin("Hello, world!"); // Create a window called "Hello,
    //  world!"
    //                                 // and append into it.

    //  ImGui::Text("This is some useful text."); // Display some text (you
    //  can
    //                                            // use a format strings too)
    //  ImGui::Checkbox(
    //    "Demo Window",
    //    &show_demo_window); // Edit bools storing our window open/close
    //    state
    //  ImGui::Checkbox("Another Window", &show_another_window);

    //  ImGui::SliderFloat("float",
    //                     &f,
    //                     0.0f,
    //                     1.0f); // Edit 1 float using a slider from 0.0f
    //                     to 1.0f
    //  ImGui::ColorEdit3(
    //    "clear color",
    //    (float*)&clear_color); // Edit 3 floats representing a color

    //  if (ImGui::Button("Button")) // Buttons return true when clicked (most
    //                               // widgets return true when
    //                               edited/activated)
    //    counter++;
    //  ImGui::SameLine();
    //  ImGui::Text("counter = %d", counter);

    //  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
    //              1000.0f / this->m_io->Framerate,
    //              this->m_io->Framerate);
    //  ImGui::End();
    //}

    //// 3. Show another simple window.
    // if (show_another_window) {
    //   ImGui::Begin(
    //     "Another Window",
    //     &show_another_window); // Pass a pointer to our bool variable (the
    //                            // window will have a closing button that
    //                            will
    //                            // clear the bool when clicked)
    //   ImGui::Text("Hello from another window!");
    //   if (ImGui::Button("Close Me"))
    //     show_another_window = false;
    //   ImGui::End();
    // }

    // Rendering
    ImGui::Render();
    glViewport(
      0, 0, (int)this->m_io->DisplaySize.x, (int)this->m_io->DisplaySize.y);
    glClearColor(clear_color.x * clear_color.w,
                 clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w,
                 clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(this->m_window);
  }
#ifdef __EMSCRIPTEN__
  EMSCRIPTEN_MAINLOOP_END;
#endif

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(this->m_gl_context);
  SDL_DestroyWindow(this->m_window);
  SDL_Quit();
}
}
