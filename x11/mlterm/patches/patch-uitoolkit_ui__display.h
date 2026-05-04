$NetBSD: patch-uitoolkit_ui__display.h,v 1.1 2026/05/04 19:51:32 tsutsui Exp $

- pull upstream change to fix "Typed keys are lost after keyboard
  focus change unntil pointer enters the mlterm window" problem
   https://github.com/arakiken/mlterm/issues/159
   https://github.com/arakiken/mlterm/commit/a8fae665

--- uitoolkit/ui_display.h.orig	2025-03-29 23:13:10.000000000 +0000
+++ uitoolkit/ui_display.h
@@ -8,6 +8,10 @@
 #include "ui.h"
 #include "ui_gc.h"
 
+#if 1
+#define AVOID_CALL_XFILTEREVENT_TWICE
+#endif
+
 #define XC_nil 1000
 
 /* Defined in ui_window.h */
