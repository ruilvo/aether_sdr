#pragma once

#define AETHER_DSP_NO_MOVE(classname) \
    classname(classname &&) = delete; \
    classname &operator=(classname &&) = delete;

#define AETHER_DSP_NO_COPY(classname)      \
    classname(const classname &) = delete; \
    classname &operator=(const classname &) = delete;

#define AETHER_DSP_NO_COPY_MOVE(classname) \
    AETHER_DSP_NO_MOVE(classname)          \
    AETHER_DSP_NO_COPY(classname)

#define AETHER_DSP_DEFAULT_MOVE(classname) \
    classname(classname &&) = default;     \
    classname &operator=(classname &&) = default;

#define AETHER_DSP_DEFAULT_COPY(classname)  \
    classname(const classname &) = default; \
    classname &operator=(const classname &) = default;

#define AETHER_DSP_DEFAULT_COPY_MOVE(classname) \
    AETHER_DSP_DEFAULT_MOVE(classname)          \
    AETHER_DSP_DEFAULT_COPY(classname)
