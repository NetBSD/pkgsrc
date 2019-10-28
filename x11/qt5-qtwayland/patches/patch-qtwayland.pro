$NetBSD: patch-qtwayland.pro,v 1.1 2019/10/28 21:35:43 nia Exp $

Do not refuse to build on non-linux.

--- qtwayland.pro.orig	2019-08-13 09:25:25.000000000 +0000
+++ qtwayland.pro
@@ -1,3 +1,2 @@
-requires(linux:!android|macos)
 requires(qtHaveModule(gui))
 load(qt_parts)
