i18n = import('i18n')

add_project_arguments(
  '-DGETTEXT_PACKAGE="' + meson.project_name() + '"',
  '-DLOCALEDIR="' + get_option('prefix') / get_option('localedir') + '"',
  language:'c',
)


i18n.gettext(
  meson.project_name(),
  args: ['--directory=',
    '--add-comments=TRANSLATORS',
    '--no-location',
    '--keyword=_',
    '--msgid-bugs=https://github.com/labwc/labwc-tweaks-gtk/issues',
    ],
    preset: 'glib',
)
