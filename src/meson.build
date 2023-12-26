finaltest_sources = [
  'main.c',
  'finaltest-application.c',
  'finaltest-window.c',
]

finaltest_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

finaltest_sources += gnome.compile_resources('finaltest-resources',
  'finaltest.gresource.xml',
  c_name: 'finaltest'
)

executable('finaltest', finaltest_sources,
  dependencies: finaltest_deps,
       install: true,
)
