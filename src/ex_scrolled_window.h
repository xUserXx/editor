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

#ifndef _EX_SCROLLED_WINDOW_H_
#define _EX_SCROLLED_WINDOW_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define EX_TYPE_SCROLLED_WINDOW             (ex_scrolled_window_get_type ())
#define EX_SCROLLED_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EX_TYPE_SCROLLED_WINDOW, ExScrolledWindow))
#define EX_SCROLLED_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EX_TYPE_SCROLLED_WINDOW, ExScrolledWindowClass))
#define EX_IS_SCROLLED_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EX_TYPE_SCROLLED_WINDOW))
#define EX_IS_SCROLLED_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EX_TYPE_SCROLLED_WINDOW))
#define EX_SCROLLED_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EX_TYPE_SCROLLED_WINDOW, ExScrolledWindowClass))

typedef struct _ExScrolledWindowClass ExScrolledWindowClass;
typedef struct _ExScrolledWindow ExScrolledWindow;
typedef struct _ExScrolledWindowPrivate ExScrolledWindowPrivate;


struct _ExScrolledWindowClass
{
	GtkScrolledWindowClass parent_class;
};

struct _ExScrolledWindow
{
	GtkScrolledWindow parent_instance;

    ExScrolledWindowPrivate *priv; 
};

GType ex_scrolled_window_get_type (void) G_GNUC_CONST;
ExScrolledWindow * ex_scrolled_window_new (void);

GtkSourceBuffer * ex_scrolled_window_get_buffer (ExScrolledWindow * sWin);

G_END_DECLS

#endif /* _EX_SCROLLED_WINDOW_H_ */

