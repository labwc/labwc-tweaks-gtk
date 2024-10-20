# Translating `labwc-tweaks-gtk`

## Translators

### Weblate

`labwc-tweaks-gtk` is now on [Weblate].

You can register [here] and use the instructions to add a new
translation or edit an existing one.

### Pull request

If you don't want to use _Weblate_ you can still branch off the repository
and create a [pull request]. We use _GNU Gettext_ for translations.

## Code contributors

1. Make sure you wrap any _new_ strings that you add, exposed in the GTK
user interface, with the gettext macro:

```C
gtk_label_new(_("My New Feature"));

```

2. If you create a new file that has exposed strings append the _filename_
to `po/POTFILES.in`

3. After adding and testing your code additions to satisfaction, backup
`po/labwc-tweaks-gtk.pot`. You need the custom header from that file for
the newly generated .pot file in the next step.

4. From the root of the repository run this:
```
xgettext --keyword=_  --add-comments -o po/labwc-tweaks-gtk.pot main.c \
stack-appearance.c stack-lang.c stack-mouse.c data/labwc-tweaks-gtk.desktop.in  \
--package-name=labwc-tweaks-gtk --package-version=0.1.0 \
--msgid-bugs-address=https://github.com/labwc/labwc-tweaks-gtk/issues
```

This generates a new pot file at `po/labwc.pot`

5. Copy the header from the original `labwc.pot` to the new one, keeping
the newly generated dates, check for sanity and commit.

[Weblate]: https://hosted.weblate.org/projects/labwc-tweaks-gtk/
[here]: https://hosted.weblate.org/engage/labwc-tweaks-gtk/
[pull request]: https://github.com/labwc/labwc-tweaks-gtk/pulls
