#ifndef NODECAFFE_BLOB_H
#define NODECAFFE_BLOB_H

#include <vector>
#include <node.h>
#include <nan.h>
#include <caffe/caffe.hpp>
#include "shared.h"

namespace NodeCaffe {

class Blob : public Nan::ObjectWrap {
 public:
  static NAN_MODULE_INIT(Init);
 private:
  explicit Blob();
  explicit Blob(const std::vector<int>& shape);
  ~Blob();

  static Nan::Persistent<v8::Function> constructor;

  static NAN_METHOD(New);

  static NAN_METHOD(reshape);

  static NAN_GETTER(get_shape);
  static NAN_SETTER(set_shape);

  static NAN_GETTER(get_data);
  static NAN_SETTER(set_data);

  static NAN_GETTER(get_diff);
  static NAN_SETTER(set_diff);

  caffe::Blob<Dtype>* blob_;
};

}

#endif
