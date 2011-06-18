$NetBSD: patch-widget-utils.c,v 1.2 2011/06/18 15:34:08 wiz Exp $

alloca.h is deprecated and doesn't exist on many systems.
http://code.google.com/p/bmpanel2/issues/detail?id=28

--- widget-utils.c.orig	2009-11-01 05:50:26.000000000 +0000
+++ widget-utils.c
@@ -1,5 +1,5 @@
 #include <stdio.h>
-#include <alloca.h>
+#include <malloc.h>
 #include "widget-utils.h"
 
 /**************************************************************************
