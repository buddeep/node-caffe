var NodeCaffe = require('../lib/node-caffe.js');
var assert = require('assert');

describe('NodeCaffe.Native',function(){
  it("should .set_mode_gpu or .set_mode_cpu",function(){
    this.timeout(10000);
    NodeCaffe.Native.set_mode_cpu();
    NodeCaffe.Native.set_mode_gpu();
  });
  it("should have a native interface", function(){
    assert(typeof NodeCaffe.Native.Layer,"function");
  });
});
describe('NodeCaffe.Native.Blob',function(){
  it("should create with defined shape", function(){
    var blob = new NodeCaffe.Native.Blob([10,2,3,5]);
    assert.deepEqual(blob.shape,[10,2,3,5]);
    blob.shape = [10,1,100,100];
    assert.deepEqual(blob.shape,[10,1,100,100]);
  });
  it("should load data from arrays", function(){
    var blob = new NodeCaffe.Native.Blob([1,1,2,2]);
    blob.data = [1,2,3,4];
    assert.deepEqual(blob.data,[1,2,3,4]);
  });
  it("should have diff", function(){
    var blob = new NodeCaffe.Native.Blob([1,1,2,3]);
    assert.deepEqual(blob.diff,[0,0,0,0,0,0]);
  });

});
