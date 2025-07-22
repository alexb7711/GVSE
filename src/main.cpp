///
/// @file src/main.cpp
///
/// This file contains the standalone executable to run GVSE as an independent process
///

#include "gvse_core.h"

// Main code
int main(int, char**)
{
   gvse::GVSECore* core = gvse::GVSECore::create();

   return 0;
}

