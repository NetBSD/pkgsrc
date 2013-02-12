$NetBSD: patch-common.mk,v 1.1.1.1 2013/02/12 23:25:35 tonnerre Exp $

--- common.mk.orig	2012-09-19 16:08:09.000000000 +0000
+++ common.mk
@@ -1,5 +1,7 @@
 UNAME=$(shell uname)
-DEBUG=1
+ifndef DEBUG
+  DEBUG=1
+endif
 COVERAGE=0
 INSTALL=install
 FLEX=flex
@@ -137,11 +139,11 @@ LIBSN_CFLAGS := $(call cflags_for_lib, l
 LIBSN_LIBS   := $(call ldflags_for_lib, libstartup-notification-1.0,startup-notification-1)
 
 # Pango
-PANGO_CFLAGS := $(call cflags_for_lib, cairo)
-PANGO_CFLAGS += $(call cflags_for_lib, pangocairo)
-I3_CPPFLAGS  += -DPANGO_SUPPORT=1
-PANGO_LIBS   := $(call ldflags_for_lib, cairo)
-PANGO_LIBS   += $(call ldflags_for_lib, pangocairo)
+#PANGO_CFLAGS := $(call cflags_for_lib, cairo)
+#PANGO_CFLAGS += $(call cflags_for_lib, pangocairo)
+I3_CPPFLAGS  += -DPANGO_SUPPORT=0
+#PANGO_LIBS   := $(call ldflags_for_lib, cairo)
+#PANGO_LIBS   += $(call ldflags_for_lib, pangocairo)
 
 # libi3
 LIBS = -L$(TOPDIR) -li3
