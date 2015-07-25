$NetBSD: patch-src_callbacks.c,v 1.1 2015/07/25 02:06:04 kamil Exp $

Add missing header for strlen(3) and strspn(3).

Backport additional changes from Fedora.
http://pkgs.fedoraproject.org/cgit/gcolor2.git/tree/gcolor2-0.4-missing-includes.patch

--- src/callbacks.c.orig	2005-07-12 18:06:12.000000000 +0000
+++ src/callbacks.c
@@ -2,8 +2,10 @@
 #  include <config.h>
 #endif
 
+#include <glib/gprintf.h>
 #include <gtk/gtk.h>
 #include <stdio.h>
+#include <string.h>
 
 #include "callbacks.h"
 #include "interface.h"
