$NetBSD: patch-config.mk,v 1.1 2016/08/26 17:16:09 joerg Exp $

--- config.mk.orig	2016-08-26 13:34:57.775528056 +0000
+++ config.mk
@@ -37,7 +37,7 @@ endif
 # includes and libs
 INCS := $(shell ${PKG_CONFIG} --cflags ${pkg_config_packs})
 CFLAGS += ${INCS}
-LDFLAGS += -lm -L${X11LIB} -lXss ${XINERAMALIBS} $(shell ${PKG_CONFIG} --libs ${pkg_config_packs})
+LDFLAGS += -lm -lXss ${XINERAMALIBS} $(shell ${PKG_CONFIG} --libs ${pkg_config_packs})
 
 # only make this an fatal error when where not cleaning
 ifneq (clean, $(MAKECMDGOALS))
