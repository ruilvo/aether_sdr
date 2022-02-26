#pragma once

#define AETHER_DSP_NO_COPY_MOVE(classname)            \
    classname(const classname &) = delete;            \
    classname(classname &&) = delete;                 \
    classname &operator=(const classname &) = delete; \
    classname &operator=(classname &&) = delete;

#if defined(_MSC_VER) && !defined(__ICL)
#define AETHER_DSP_SUPPRESS_C4251 _Pragma("warning(suppress:4251)")
#else
#define AETHER_DSP_SUPPRESS_C4251
#endif
