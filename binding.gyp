{
  "targets": [
    {
      "target_name": "terminal-size",
      "sources": [
        "terminal-size.cc",
        "tsize_linux.cc",
        "tsize_win.cpp"
      ],
      'conditions': [
        ['OS != "linux"', {
          'sources!': [
            # Linux-only; exclude on other platforms.
            'tsize_linux.cc',
          ]
        }],
        ['OS != "win"', {
          'sources!': [
            # Windows-only; exclude on other platforms.
            'tsize_win.cpp',
          ]
        }]
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
