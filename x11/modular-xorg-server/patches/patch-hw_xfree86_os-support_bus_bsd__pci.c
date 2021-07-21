$NetBSD: patch-hw_xfree86_os-support_bus_bsd__pci.c,v 1.1 2021/07/21 21:50:29 tnn Exp $

compiler.h needs to go after xf86.h so that CARD8 is defined
at that point. Fixes build on NetBSD/alpha.
But probabiy this file shouldn't be compiled at all.

--- hw/xfree86/os-support/bus/bsd_pci.c.orig	2021-07-08 19:22:18.000000000 +0000
+++ hw/xfree86/os-support/bus/bsd_pci.c
@@ -40,10 +40,10 @@
 #endif
 
 #include <stdio.h>
-#include "compiler.h"
 #include "xf86.h"
 #include "xf86Priv.h"
 #include "xf86_OSlib.h"
+#include "compiler.h"
 #include "Pci.h"
 
 #include "pciaccess.h"
