$NetBSD: patch-src_dock.cpp,v 1.1 2024/08/18 07:44:23 pin Exp $

Port to Qt6.

--- src/dock.cpp.orig	2024-01-14 11:02:54.000000000 +0000
+++ src/dock.cpp
@@ -24,7 +24,6 @@
 #include <obrender/render.h>
 #include "tree.h"
 
-#include <QX11Info>
 // FIXME: how to support XCB or Wayland?
 #include <X11/Xlib.h>
 
