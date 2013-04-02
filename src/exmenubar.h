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

#ifndef _EXMENUBAR_H_
#define _EXMENUBAR_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define EX_TYPE_MENUBAR             (ex_menubar_get_type ())
#define EX_MENUBAR(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), EX_TYPE_MENUBAR, exmenubar))
#define EX_MENUBAR_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), EX_TYPE_MENUBAR, exmenubarClass))
#define EX_IS_MENUBAR(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EX_TYPE_MENUBAR))
#define EX_IS_MENUBAR_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), EX_TYPE_MENUBAR))
#define EX_MENUBAR_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), EX_TYPE_MENUBAR, exmenubarClass))

typedef struct _exmenubarClass exmenubarClass;
typedef struct _exmenubar exmenubar;
typedef struct _exmenubarPrivate exmenubarPrivate;


struct _exmenubarClass
{
	GtkMenuBarClass parent_class;
};

struct _exmenubar
{
	GtkMenuBar parent_instance;

    exmenubarPrivate *priv; 
};

GType ex_menubar_get_type (void) G_GNUC_CONST;
exmenubar * ex_menubar_new(void);

void ex_menubar_create_default_menus (exmenubar * menubar);
void ex_menubar_create_default_menu_items (exmenubar * menubar);
void ex_menubar_mount (exmenubar * menubar);

G_END_DECLS

#endif /* _EXMENUBAR_H_ */

