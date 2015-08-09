#include <nan.h>
#include "root.h"

#include <caffe/caffe.hpp>

namespace NodeCaffe {

NAN_METHOD(set_mode_cpu) {
  caffe::Caffe::set_mode(caffe::Caffe::CPU);
}

NAN_METHOD(set_mode_gpu) {
  caffe::Caffe::set_mode(caffe::Caffe::GPU);
}

}
