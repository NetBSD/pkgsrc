$NetBSD: patch-qtwayland.pro,v 1.2 2020/06/02 06:41:03 adam Exp $

Do not refuse to build on non-linux.

--- qtwayland.pro.orig	2020-06-01 19:27:25.040097860 +0000
+++ qtwayland.pro
@@ -1,3 +1,2 @@
-requires(linux:!android|macos|qnx)
 requires(qtHaveModule(gui))
 load(qt_parts)
