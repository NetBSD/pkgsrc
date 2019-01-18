$NetBSD: patch-util_test-menu-spec.c,v 1.1 2019/01/18 09:48:16 martin Exp $

Build fix - uses setlocale().

--- util/test-menu-spec.c.orig	2018-05-27 13:58:09.000000000 +0200
+++ util/test-menu-spec.c	2019-01-18 10:43:32.367675376 +0100
@@ -23,6 +23,7 @@
 #include "matemenu-tree.h"
 
 #include <string.h>
+#include <locale.h>
 
 static char     *menu_file = NULL;
 static gboolean  monitor = FALSE;
