#include <node.h>
#include <nan.h>

#include "NodeCaffe/root.h"
#include "NodeCaffe/Blob.h"
#include "NodeCaffe/Layer.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

void InitAll(Handle<Object> exports) {
  exports->Set(Nan::New<v8::String>("set_mode_cpu").ToLocalChecked(),
      Nan::New<FunctionTemplate>(NodeCaffe::set_mode_cpu)->GetFunction());
  exports->Set(Nan::New<v8::String>("set_mode_gpu").ToLocalChecked(),
      Nan::New<FunctionTemplate>(NodeCaffe::set_mode_gpu)->GetFunction());
  NodeCaffe::Blob::Init(exports);
  //NodeCaffe::Layer::Init(exports);
}
NODE_MODULE(NativeNodeCaffe, InitAll);
