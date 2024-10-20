install_data(
  'labwc-tweaks-gtk.svg',
  install_dir : join_paths(get_option('datadir'), 'icons', 'hicolor', 'scalable', 'apps'),
)

if get_option('nls').disabled() or msgfmt.found() == false
  install_data(
    'labwc-tweaks-gtk.desktop.in',
    rename : 'labwc-tweaks-gtk.desktop',
    install_dir : join_paths(get_option('datadir'), 'applications'),
  )
else
  desktop = i18n.merge_file(
    input: 'labwc-tweaks-gtk.desktop.in',
    output: 'labwc-tweaks-gtk.desktop',
    type: 'desktop',
    po_dir: '../po',
    install: true,
    install_dir : join_paths(get_option('datadir'), 'applications'),
  )
endif
