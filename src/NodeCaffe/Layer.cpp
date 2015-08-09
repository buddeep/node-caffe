#include "Layer.h"

namespace NodeCaffe {

Nan::Persistent<v8::Function> Layer::constructor;

Layer::Layer() {}

Layer::~Layer() {}

NAN_MODULE_INIT(Layer::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("Layer").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  //v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();

  constructor.Reset(tpl->GetFunction());
  Nan::Set(target, Nan::New("Layer").ToLocalChecked(),tpl->GetFunction());
}

NAN_METHOD(Layer::New) {
  if (info.IsConstructCall()) {
    Layer *obj = new Layer();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = {info[0]};
    v8::Local<v8::Function> cons = Nan::New(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc,argv));
  }
}

}
