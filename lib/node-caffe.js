var path = require('path');
var ProtoBuf = require('protobufjs');

var NodeCaffe = {};
NodeCaffe.Native = require('../build/Release/NativeNodeCaffe')
NodeCaffe.ProtoBuf = require('./node-caffe/ProtoBuf');
NodeCaffe.IO = require('./node-caffe/IO');
module.exports = NodeCaffe;
