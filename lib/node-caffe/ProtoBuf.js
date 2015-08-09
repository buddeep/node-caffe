var path = require('path');
var ProtoBuf = require('protobufjs');

PB = {};
PB._builder = ProtoBuf.loadProtoFile(path.join(__dirname,"..","caffe.proto"));
PB = PB._builder.build().caffe;
module.exports = PB;
