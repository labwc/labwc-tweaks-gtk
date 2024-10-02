/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef STATE_H
#define STATE_H
#include <gtk/gtk.h>

struct state {
	GtkWidget *window;
	struct {
		GtkWidget *corner_radius;
		GtkWidget *button_layout;
		GtkWidget *show_title;
		GtkWidget *drop_shadows;
		GtkWidget *openbox_theme_name;
		GtkWidget *gtk_theme_name;
		GtkWidget *icon_theme_name;
		GtkWidget *cursor_theme_name;
		GtkWidget *cursor_size;
		GtkWidget *natural_scroll;
		GtkWidget *double_click_time;
		GtkWidget *top_max;
		GtkWidget *keyboard_layout;
		GtkWidget *placement;

	} widgets;
	GSettings *settings;
};

#endif /* STATE_H */
