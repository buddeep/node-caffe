#include "Blob.h"

namespace NodeCaffe {

Nan::Persistent<v8::Function> Blob::constructor;

Blob::~Blob() {}
Blob::Blob() {
  blob_ = new ::caffe::Blob<Dtype>();
}
Blob::Blob(const std::vector<int>& shape) {
  blob_ = new ::caffe::Blob<Dtype>(shape);
}

NAN_MODULE_INIT(Blob::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("Blob").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();

  Nan::SetPrototypeMethod(tpl,"reshape",Blob::reshape);

  SetAccessor(proto, Nan::New("shape").ToLocalChecked(),
      Blob::get_shape, Blob::set_shape);
  SetAccessor(proto, Nan::New("data").ToLocalChecked(),
      Blob::get_data, Blob::set_data);
  SetAccessor(proto, Nan::New("diff").ToLocalChecked(),
      Blob::get_diff, Blob::set_diff);

  constructor.Reset(tpl->GetFunction());
  Nan::Set(target, Nan::New("Blob").ToLocalChecked(),tpl->GetFunction());
}

NAN_METHOD(Blob::New) {
  if (info.IsConstructCall()) {
    Blob *obj;
    if (info[0]->IsUndefined()) {
      obj = new Blob();
    } else {
      std::vector<int> shape;
      v8::Local<v8::Array> shape_arr = v8::Local<v8::Array>::Cast(info[0]);
      for (uint32_t i = 0; i < shape_arr->Length(); i++) {
        int dim = shape_arr->Get(i)->IntegerValue();
        shape.push_back(dim);
      }
      obj = new Blob(shape);
    }
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
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape;
  v8::Local<v8::Array> shape_arr = v8::Local<v8::Array>::Cast(info[0]);
  for (uint32_t i = 0; i < shape_arr->Length(); i++) {
    int dim = shape_arr->Get(i)->IntegerValue();
    shape.push_back(dim);
  }
  obj->blob_->Reshape(shape);
}

NAN_GETTER(Blob::get_shape) {
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape = obj->blob_->shape();
  v8::Local<v8::Array> result = Nan::New<v8::Array>(shape.size());
  for (size_t i = 0; i < shape.size(); i++) {
    result->Set(i, Nan::New<v8::Number>(shape[i]));
  }
  info.GetReturnValue().Set(result);
}
NAN_SETTER(Blob::set_shape) {
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape;
  v8::Local<v8::Array> shape_arr = v8::Local<v8::Array>::Cast(value);
  for (uint32_t i = 0; i < shape_arr->Length(); i++) {
    int j = shape_arr->Get(i)->IntegerValue();
    shape.push_back(j);
  }
  obj->blob_->Reshape(shape);
}

NAN_GETTER(Blob::get_data) {
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape = obj->blob_->shape();
  int count = shape[0];
  for (size_t i = 1; i < shape.size(); i++) { count *= shape[i]; }

  Dtype *data = obj->blob_->mutable_cpu_data();
  v8::Local<v8::Array> result = Nan::New<v8::Array>(count);
  for (int i = 0; i < count; i++) {
    result->Set(i, Nan::New<v8::Number>(data[i]));
  }
  info.GetReturnValue().Set(result);
}
NAN_SETTER(Blob::set_data) {
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape = obj->blob_->shape();
  int count = shape[0];
  for (size_t i = 1; i < shape.size(); i++) { count *= shape[i]; }
  Dtype *data = new Dtype[count];

  v8::Local<v8::Array> arr = v8::Local<v8::Array>::Cast(value);
  int loCountArrLen = (count < (int)arr->Length()) ? count : arr->Length();
  for (int i = 0; i < loCountArrLen; i++) {
    Dtype j = arr->Get(i)->NumberValue();
    data[i] = j;
  }
  obj->blob_->set_cpu_data(data);
}

NAN_GETTER(Blob::get_diff) {
  Blob* obj = ObjectWrap::Unwrap<Blob>(info.This());
  std::vector<int> shape = obj->blob_->shape();
  int count = shape[0];
  for (size_t i = 1; i < shape.size(); i++) { count *= shape[i]; }

  Dtype *data = obj->blob_->mutable_cpu_diff();
  v8::Local<v8::Array> result = Nan::New<v8::Array>(count);
  for (int i = 0; i < count; i++) {
    result->Set(i, Nan::New<v8::Number>(data[i]));
  }
  info.GetReturnValue().Set(result);
}
NAN_SETTER(Blob::set_diff) {
}

}
