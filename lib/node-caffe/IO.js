var ndarray = require('ndarray');

var IO = {};

IO.blobproto_to_ndarray = function(blob,return_diff){
  return ndarray(
    return_diff ? blob.diff : blob.data,
    [blob.num,blob.channels,blob.height,blob.width]
  );
}
IO.ndarray_to_blobproto = null;

IO.ndarray_list_to_blobprotovec_str = null;
IO.blobprotovec_str_to_ndarray_list = null;

IO.ndarray_to_datum = null;
IO.datum_to_ndarray = null;

IO.load_image = null;
IO.resize_image = null;
IO.oversample = null;

module.exports = IO;
