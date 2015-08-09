#ifndef NODECAFFE_BLOB_H
#define NODECAFFE_BLOB_H

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
  ~Blob();

  static Nan::Persistent<v8::Function> constructor;

  static NAN_METHOD(New);

  static NAN_METHOD(reshape);

  static NAN_GETTER(get_num);
  static NAN_SETTER(set_num);

  static NAN_GETTER(get_channels);
  static NAN_SETTER(set_channels);

  static NAN_GETTER(get_height);
  static NAN_SETTER(set_height);

  static NAN_GETTER(get_width);
  static NAN_SETTER(set_width);

  static NAN_GETTER(get_count);
  static NAN_SETTER(set_count);

  static NAN_GETTER(get_data);
  static NAN_SETTER(set_data);

  static NAN_GETTER(get_diff);
  static NAN_SETTER(set_diff);

  caffe::Blob<Dtype> blob_;
};

}

#endif
