var NodeCaffe = require('../lib/node-caffe.js');
var assert = require('assert');

describe('NodeCaffe.Native',function(){
  it("should .set_mode_gpu or .set_mode_cpu",function(){
    NodeCaffe.Native.set_mode_cpu();
    NodeCaffe.Native.set_mode_gpu();
  });
  it("should have a native interface", function(){
    assert(typeof NodeCaffe.Native.Layer,"function");
  });
});
