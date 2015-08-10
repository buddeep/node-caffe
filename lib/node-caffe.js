var path = require('path');
var ProtoBuf = require('protobufjs');

var NodeCaffe = {};
if (process.env.NODE_CAFFE_DEBUG) {
  NodeCaffe.Native = require('../build/Debug/NativeNodeCaffe')
} else {
  NodeCaffe.Native = require('../build/Release/NativeNodeCaffe')
}
NodeCaffe.ProtoBuf = require('./node-caffe/ProtoBuf');
NodeCaffe.IO = require('./node-caffe/IO');
module.exports = NodeCaffe;
