/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * Editor
 * Copyright (C) 2013 userx <userx@osires>
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

#ifndef _EXTOOLBAR_H_
#define _EXTOOLBAR_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define EX_TYPE_TOOLBAR             (extoolbar_get_type ())
#define EX_TOOLBAR(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EX_TYPE_TOOLBAR, extoolbar))
#define EX_TOOLBAR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EX_TYPE_TOOLBAR, extoolbarClass))
#define EX_IS_TOOLBAR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EX_TYPE_TOOLBAR))
#define EX_IS_TOOLBAR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EX_TYPE_TOOLBAR))
#define EX_TOOLBAR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EX_TYPE_TOOLBAR, extoolbarClass))

typedef struct _extoolbarClass extoolbarClass;
typedef struct _extoolbar extoolbar;
typedef struct _extoolbarPrivate extoolbarPrivate;


struct _extoolbarClass
{
	GtkToolbarClass parent_class;
};

struct _extoolbar
{
	GtkToolbar parent_instance;

    extoolbarPrivate *priv; 
};

GType extoolbar_get_type (void) G_GNUC_CONST;
extoolbar * extoolbar_new (void);
G_END_DECLS

#endif /* _EXTOOLBAR_H_ */

