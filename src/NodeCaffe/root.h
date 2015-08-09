#ifndef NODECAFFE_GLOBALS_H
#define NODECAFFE_GLOBALS_H

#include <nan.h>

namespace NodeCaffe {

NAN_METHOD(set_mode_cpu);
NAN_METHOD(set_mode_gpu);
//TODO NAN_METHOD(set_device)

}

#endif
