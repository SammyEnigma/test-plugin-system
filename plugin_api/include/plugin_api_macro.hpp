#pragma once

#ifdef __cplusplus
#   define PLUGIN_EXTERN_C extern "C"
#else
#   define PLUGIN_EXTERN_C
#endif

#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
#   ifdef __GNUC__
#       define PLUGIN_EXPORT PLUGIN_EXTERN_C __attribute__ ((dllexport))
#       define PLUGIN_IMPORT PLUGIN_EXTERN_C __attribute__ ((dllimport))
#   else
#       define PLUGIN_EXPORT PLUGIN_EXTERN_C _declspec(dllexport)
#       define PLUGIN_IMPORT PLUGIN_EXTERN_C _declspec(dllimport)
#   endif
#   define PLUGIN_PREFIX ""
#   define PLUGIN_SUFFIX ".dll"
#else
#   if __GNUC__ >= 4
#       define PLUGIN_EXPORT PLUGIN_EXTERN_C __attribute__ ((visibility ("default")))
#       define PLUGIN_IMPORT
#   else
#       define PLUGIN_EXPORT PLUGIN_EXTERN_C
#       define PLUGIN_IMPORT PLUGIN_EXTERN_C
#   endif
#   define PLUGIN_PREFIX "lib"
#   define PLUGIN_SUFFIX ".so"
#endif

#ifdef PLUGIN_API_LIBRARY
#   define PLUGIN_API PLUGIN_EXPORT
#else
#   define PLUGIN_API PLUGIN_IMPORT
#endif