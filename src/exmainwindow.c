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

#include "definitions.h"


struct _ex_mainwindowPrivate {
	GtkWidget * grid;

	exmenubar * Ex_MenuBar;
	extoolbar * Ex_ToolBar;
	ExScrolledWindow * Ex_sWin;
};

#define EXMAIN_WINDOW_GET_PRIVATE(o)  (G_TYPE_INSTANCE_GET_PRIVATE ((o), EXMAIN_TYPE_WINDOW, ex_mainwindowPrivate))



G_DEFINE_TYPE (ex_mainwindow, exmainwindow, GTK_TYPE_WINDOW);

// constructor ::
ex_mainwindow * exmainwindow_new() {

	return g_object_new(EXMAIN_TYPE_WINDOW, NULL);

}

// initialize private data ::
static void exmainwindow_init (ex_mainwindow * exmainwindow) {
	
    ex_mainwindowPrivate * priv = EXMAIN_WINDOW_GET_PRIVATE(exmainwindow);

	/* TODO: Add initialization code here */
	gtk_window_set_type_hint (GTK_WINDOW(exmainwindow), GDK_WINDOW_TYPE_HINT_NORMAL);
	gtk_window_set_default_size (GTK_WINDOW(exmainwindow), 640, 480);
	gtk_window_set_position (GTK_WINDOW(exmainwindow), GTK_WIN_POS_CENTER);
	
	priv->grid = gtk_grid_new();
	exmainwindow_set_homogeneous (EXMAIN_WINDOW(exmainwindow), TRUE, TRUE);
	gtk_container_add(GTK_CONTAINER(exmainwindow), priv->grid);
	
	priv->Ex_MenuBar = ex_menubar_new ();
	priv->Ex_ToolBar = extoolbar_new ();
	priv->Ex_sWin = ex_scrolled_window_new ();
	
	exmainwindow_add_next_to (EXMAIN_WINDOW (exmainwindow), GTK_WIDGET(priv->Ex_MenuBar), NULL, GTK_POS_LEFT, 640, 10);
	exmainwindow_add_next_to (EXMAIN_WINDOW (exmainwindow), GTK_WIDGET(priv->Ex_ToolBar), GTK_WIDGET(priv->Ex_MenuBar), GTK_POS_BOTTOM, 640, 15);
	exmainwindow_add_next_to (EXMAIN_WINDOW (exmainwindow), GTK_WIDGET(priv->Ex_sWin), GTK_WIDGET(priv->Ex_ToolBar), GTK_POS_BOTTOM, 640, 150);
	
	g_signal_connect(exmainwindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	
}

// destructor ::
static void exmainwindow_finalize (GObject *object) {
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (exmainwindow_parent_class)->finalize (object);
}

static void exmainwindow_class_init (ex_mainwindowClass * klass) {
	
	GObjectClass * object_class = G_OBJECT_CLASS (klass);
/*	GtkWindowClass * parent_class = GTK_WINDOW_CLASS (klass);*/

	g_type_class_add_private (klass, sizeof (ex_mainwindowPrivate));

	object_class->finalize = exmainwindow_finalize;
	
}


void exmainwindow_set_homogeneous (ex_mainwindow * exmainwindow, gboolean row, gboolean column) {
	
	/* TODO: Add public function implementation here */
	ex_mainwindowPrivate * priv = EXMAIN_WINDOW_GET_PRIVATE (exmainwindow);

	gtk_grid_set_row_homogeneous (GTK_GRID(priv->grid), row);
	gtk_grid_set_column_homogeneous (GTK_GRID(priv->grid), column);
	
}

void exmainwindow_add (ex_mainwindow * exmainwindow, GtkWidget * child, gint left, gint top,
                       gint width, gint height) {
	
	/* TODO: Add public function implementation here */
	ex_mainwindowPrivate * priv = EXMAIN_WINDOW_GET_PRIVATE (exmainwindow);

	gtk_grid_attach (GTK_GRID(priv->grid), child, left, top, width, height);
	
}

void exmainwindow_add_next_to (ex_mainwindow * exmainwindow, GtkWidget * child, GtkWidget * sibling,
                               GtkPositionType side, gint width, gint height) {

	
	/* TODO: Add public function implementation here */
	ex_mainwindowPrivate * priv = EXMAIN_WINDOW_GET_PRIVATE (exmainwindow);

	gtk_grid_attach_next_to (GTK_GRID(priv->grid), child, sibling, side, width, height);
		
}

