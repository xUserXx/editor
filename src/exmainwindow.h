/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * Editor
 * Copyright (C) 2013 UserX <userx.gnu@gmail.com>
 * 
 * Editor is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Editor is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _EXMAINWINDOW_H_
#define _EXMAINWINDOW_H_

#include <glib-object.h>


G_BEGIN_DECLS

#define EXMAIN_TYPE_WINDOW             (exmainwindow_get_type ())
#define EXMAIN_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXMAIN_TYPE_WINDOW, ex_mainwindow))
#define EXMAIN_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EXMAIN_TYPE_WINDOW, ex_mainwindowClass))
#define EXMAIN_IS_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXMAIN_TYPE_WINDOW))
#define EXMAIN_IS_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EXMAIN_TYPE_WINDOW))
#define EXMAIN_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EXMAIN_TYPE_WINDOW, ex_mainwindowClass))

typedef struct _ex_mainwindowClass ex_mainwindowClass;
typedef struct _ex_mainwindow ex_mainwindow;
typedef struct _ex_mainwindowPrivate ex_mainwindowPrivate;


struct _ex_mainwindowClass
{
	GtkWindowClass parent_class;
};

struct _ex_mainwindow
{
	GtkWindow parent_instance;

    ex_mainwindowPrivate *priv; 
};

GType exmainwindow_get_type (void) G_GNUC_CONST;
ex_mainwindow * exmainwindow_new();

void exmainwindow_set_homogeneous (ex_mainwindow * window, gboolean row, gboolean column);
void exmainwindow_add (ex_mainwindow * window, GtkWidget * child, gint left, gint top, gint width, gint height);
void exmainwindow_add_next_to (ex_mainwindow * window, GtkWidget * child, GtkWidget * sibling, GtkPositionType side, gint width, gint height);

G_END_DECLS

#endif /* _EXMAINWINDOW_H_ */

