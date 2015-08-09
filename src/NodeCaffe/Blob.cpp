#include "Blob.h"

namespace NodeCaffe {

Persistent<v8::Function> Blob::constructor;

Blob::Blob() {}

Blob::~Blob() {}

NAN_MODULE_INIT(Blob::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("Blob").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();

  SetPrototypeMethod(tpl,"reshape",Blob::reshape);

  SetAccessor(proto, Nan::New("num").ToLocalChecked(),
      Blob::get_num, Blob::set_num);
  SetAccessor(proto, Nan::New("channels").ToLocalChecked(),
      Blob::get_channels, Blob::set_channels);
  SetAccessor(proto, Nan::New("height").ToLocalChecked(),
      Blob::get_height, Blob::set_height);
  SetAccessor(proto, Nan::New("width").ToLocalChecked(),
      Blob::get_width, Blob::set_width);
  /*
  SetAccessor(proto, Nan::New("data").ToLocalChecked(),
      Blob::get_data, Blob::set_data);
  SetAccessor(proto, Nan::New("diff").ToLocalChecked(),
      Blob::get_diff, Blob::set_diff);
  */

  constructor.Reset(tpl->GetFunction());
  Set(target, Nan::New("Blob").ToLocalChecked(),tpl->GetFunction());
}

NAN_METHOD(Blob::New) {
  if (info.IsConstructCall()) {
    Blob *obj = new Blob();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = {info[0]};
    v8::Local<v8::Function> cons = Nan::New(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc,argv));
  }
}

NAN_METHOD(Blob::reshape) {
  //Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  // TODO
}


NAN_GETTER(Blob::get_num) { /* TODO */ }
NAN_SETTER(Blob::set_num) { /* TODO */ }

NAN_GETTER(Blob::get_channels) { /* TODO */ }
NAN_SETTER(Blob::set_channels) { /* TODO */ }

NAN_GETTER(Blob::get_height) { /* TODO */ }
NAN_SETTER(Blob::set_height) { /* TODO */ }

NAN_GETTER(Blob::get_width) { /* TODO */ }
NAN_SETTER(Blob::set_width) { /* TODO */ }

NAN_GETTER(Blob::get_count) { /* TODO */ }
NAN_SETTER(Blob::set_count) { /* TODO */ }

NAN_GETTER(Blob::get_data) { /* TODO */ }
NAN_SETTER(Blob::set_data) { /* TODO */ }

NAN_GETTER(Blob::get_diff) { /* TODO */ }
NAN_SETTER(Blob::set_diff) { /* TODO */ }

}
