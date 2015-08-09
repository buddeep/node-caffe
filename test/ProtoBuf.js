var NodeCaffe = require('../lib/node-caffe.js');
var assert = require('assert');

describe('NodeCaffe.ProtoBuf',function(){
  it("should load caffe.proto", function(){
    var blob_shape = new NodeCaffe.ProtoBuf.BlobShape({dim: 3});
    var blob_proto = new NodeCaffe.ProtoBuf.BlobProto({
      shape: blob_shape,
      data: [1.0, 1.0, 1.0]
    });
    assert(blob_proto.encode64().length > 0);
  });
});
