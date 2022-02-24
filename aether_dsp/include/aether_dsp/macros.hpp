#pragma once

#define AETHER_DSP_NO_COPY_MOVE(classname)            \
    classname(const classname &) = delete;            \
    classname(classname &&) = delete;                 \
    classname &operator=(const classname &) = delete; \
    classname &operator=(classname &&) = delete;
