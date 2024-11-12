// SPDX-License-Identifier: GPL-2.0-only
#include <assert.h>
#include "environment.h"
#include "state.h"
#include "update.h"
#include "xml.h"

static void
spawn_sync(char const *command)
{
	GError *err = NULL;
	assert(command);
	g_spawn_command_line_sync(command, NULL, NULL, NULL, &err);
	if (err) {
		fprintf(stderr, "warn: could not find %s\n", command);
		g_error_free(err);
	}
}

static const char
*first_field(const char *s, char delim)
{
	if (!s) {
		return NULL;
	}
	char *p = strchr(s, delim);
	if (p) {
		*p = '\0';
	}
	return s;
}

static void
set_value_num(GSettings *settings, const char *key, int value)
{
	g_settings_set_value(settings, key, g_variant_new("i", value));
}

static void
set_value(GSettings *settings, const char *key, const char *value)
{
	if (!value) {
		fprintf(stderr, "warn: cannot set '%s' - no value specified\n", key);
		return;
	}
	g_settings_set_value(settings, key, g_variant_new("s", value));
}

#define COMBO_TEXT(w) gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(w))
#define SPIN_BUTTON_VAL(w) gtk_spin_button_get_value(GTK_SPIN_BUTTON(w))
#define SPIN_BUTTON_VAL_INT(w) (int)SPIN_BUTTON_VAL(w)
#define GTK_ENTRY_TEXT(w) gtk_entry_get_text(GTK_ENTRY(w))

void
update(GtkWidget *widget, gpointer data)
{
	struct state *state = (struct state *)data;

	/* ~/.config/labwc/rc.xml */
	xml_set_num("/labwc_config/theme/cornerradius", SPIN_BUTTON_VAL(state->widgets.corner_radius));
	xml_set("/labwc_config/theme/name", COMBO_TEXT(state->widgets.openbox_theme_name));
	xml_set("/labwc_config/libinput/device/naturalscroll", COMBO_TEXT(state->widgets.natural_scroll));
	xml_set("/labwc_config/theme/dropShadows", COMBO_TEXT(state->widgets.drop_shadows));
	xml_set("/labwc_config/theme/titlebar/layout", (char *)GTK_ENTRY_TEXT(state->widgets.button_layout));
	xml_set("/labwc_config/theme/titlebar/showTitle", COMBO_TEXT(state->widgets.show_title));
	xml_save();

	/* gsettings */
	set_value(state->settings, "cursor-theme", COMBO_TEXT(state->widgets.cursor_theme_name));
	set_value_num(state->settings, "cursor-size", SPIN_BUTTON_VAL_INT(state->widgets.cursor_size));
	set_value(state->settings, "gtk-theme", COMBO_TEXT(state->widgets.gtk_theme_name));
	set_value(state->settings, "icon-theme", COMBO_TEXT(state->widgets.icon_theme_name));

	/* ~/.config/labwc/environment */
	environment_set("XCURSOR_THEME", COMBO_TEXT(state->widgets.cursor_theme_name));
	environment_set_num("XCURSOR_SIZE", SPIN_BUTTON_VAL_INT(state->widgets.cursor_size));
	environment_set("XKB_DEFAULT_LAYOUT", first_field(COMBO_TEXT(state->widgets.keyboard_layout), ' '));

	if (!g_strcmp0(COMBO_TEXT(state->widgets.openbox_theme_name), "GTK")) {
		spawn_sync("labwc-gtktheme.py");
	}

	/* reconfigure labwc */
	if (!fork()) {
		execl("/bin/sh", "/bin/sh", "-c", "labwc -r", (void *)NULL);
	}
}

