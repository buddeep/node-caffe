#ifndef NODECAFFE_LAYER_H
#define NODECAFFE_LAYER_H

#include <node.h>
#include <nan.h>
#include "shared.h"

namespace NodeCaffe {

class Layer : public Nan::ObjectWrap {
 public:
  static NAN_MODULE_INIT(Init);
 private:
  explicit Layer();
  ~Layer();

  static NAN_METHOD(New);
  static Nan::Persistent<v8::Function> constructor;
};

}

#endif
