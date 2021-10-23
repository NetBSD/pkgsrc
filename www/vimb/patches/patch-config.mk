$NetBSD: patch-config.mk,v 1.1 2021/10/23 21:29:16 leot Exp $

Honors user's LDFLAGS for web extension.

--- config.mk.orig	2020-01-02 22:17:49.000000000 +0000
+++ config.mk
@@ -36,7 +36,7 @@ endif
 EXTTARGET   = webext_main.so
 EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.0)
 EXTCPPFLAGS = $(CPPFLAGS)
-EXTLDFLAGS  = $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
+EXTLDFLAGS  = ${LDFLAGS} $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
 
 # flags used for the main application
 CFLAGS     += $(shell pkg-config --cflags $(LIBS))
