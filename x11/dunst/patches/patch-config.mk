$NetBSD: patch-config.mk,v 1.2 2017/07/20 10:39:25 leot Exp $

Do not manually provide an undefined (and not needed) ${X11LIB} to LDFLAGS.

--- config.mk.orig	2017-07-12 08:22:04.000000000 +0000
+++ config.mk
@@ -42,7 +42,7 @@ endif
 # includes and libs
 INCS := $(shell ${PKG_CONFIG} --cflags ${pkg_config_packs})
 CFLAGS += ${INCS}
-LDFLAGS += -lm -L${X11LIB} -lXss $(shell ${PKG_CONFIG} --libs ${pkg_config_packs})
+LDFLAGS += -lm -lXss $(shell ${PKG_CONFIG} --libs ${pkg_config_packs})
 
 # only make this an fatal error when where not cleaning
 ifneq (clean, $(MAKECMDGOALS))
