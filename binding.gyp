{
  'targets': [
    {
      'target_name': 'NativeNodeCaffe',
      'sources': [
          'src/NodeCaffe.cpp',
          'src/NodeCaffe/root.cpp',
          'src/NodeCaffe/Blob.cpp',
          'src/NodeCaffe/Layer.cpp'
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")',
        '<!(echo $CAFFE_ROOT/include)',
        '<!(echo $CAFFE_ROOT/.build_release/src)',
        '<!(echo $CUDA_PATH/include)'
      ],
      'libraries': [
        '<!(echo $CAFFE_ROOT/build/lib/libcaffe.a)',
        '<!(echo -L$CUDA_PATH/lib)',
        '-lcudart',
        '-lcublas',
        '-lcurand',
        '-lglog',
        '-lprotobuf',
        '-lleveldb',
        '-llmdb'
      ],
      'dependencies': [
      ],
      'conditions': [
        ['OS=="win"', {
          'dependencies': [
          ]
        }],
        ['OS=="mac"', {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'MACOSX_DEPLOYMENT_TARGET': '10.5',
            'OTHER_CFLAGS': [
            ]
          },
          'libraries': [
          ],
        }]
      ]
    }
  ]
}
