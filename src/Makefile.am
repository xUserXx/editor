## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(EDITOR_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = editor

editor_SOURCES = \
	main.c \
	exmainwindow.c \
	exmainwindow.h \
	definitions.h \
	exmenubar.c \
	exmenubar.h \
	extoolbar.c \
	extoolbar.h \
	ex_scrolled_window.c \
	ex_scrolled_window.h

editor_LDFLAGS = \
	-Wl,--export-dynamic

editor_LDADD = $(EDITOR_LIBS)


