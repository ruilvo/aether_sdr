#pragma once

#define AETHER_DSP_NO_COPY_MOVE(classname)            \
    classname(const classname &) = delete;            \
    classname(classname &&) = delete;                 \
    classname &operator=(const classname &) = delete; \
    classname &operator=(classname &&) = delete;

#define AETHER_DSP_DEFAULT_COPY_MOVE(classname)        \
    classname(const classname &) = default;            \
    classname(classname &&) = default;                 \
    classname &operator=(const classname &) = default; \
    classname &operator=(classname &&) = default;

#if defined(_MSC_VER) && !defined(__ICL)
    #define AETHER_DSP_SUPPRESS_C4251 _Pragma("warning(suppress:4251)")
#else
    #define AETHER_DSP_SUPPRESS_C4251
#endif
