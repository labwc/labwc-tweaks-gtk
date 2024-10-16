project(
  'labwc-tweaks-gtk',
  'c',
  version: '0.1.0',
  license: 'GPL-2.0-only',
  default_options: ['c_std=c11', 'warning_level=3'],
)

add_project_arguments(['-Wno-unused-parameter'], language: 'c',)

gtkdeps = [dependency('gtk+-3.0'), dependency('libxml-2.0'), dependency('gio-2.0')]

conf_data = configuration_data()

msgfmt = find_program('msgfmt', required: get_option('nls'))
if msgfmt.found()
  source_root = meson.current_source_dir()
  conf_data.set('HAVE_NLS', 1)
  subdir('po')
else
  conf_data.set('HAVE_NLS', 0)
endif

configure_file(output: 'config.h',  configuration: conf_data)

executable(
  meson.project_name(),
  files(
    'main.c',
    'xml.c',
    'environment.c',
    'theme.c',
    'keyboard-layouts.c',
    'stack-appearance.c',
    'stack-lang.c',
    'stack-mouse.c',
    'update.c',
  ),
  include_directories: '.',
  dependencies: gtkdeps,
  install : true,
)

subdir('tests')
subdir('data')
