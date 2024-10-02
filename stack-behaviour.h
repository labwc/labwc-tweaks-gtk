/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef STACK_BEHAVIOUR_H
#define STACK_BEHAVIOUR_H
#include <gtk/gtk.h>

struct state;

void stack_behaviour_init(struct state *state, GtkWidget *stack);

#endif
