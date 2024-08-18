$NetBSD: patch-src_tree.cpp,v 1.1 2024/08/18 07:44:23 pin Exp $

Port to Qt6.

--- src/tree.cpp.orig	2024-01-14 11:02:54.000000000 +0000
+++ src/tree.cpp
@@ -16,7 +16,7 @@
    See the COPYING file for a copy of the GNU General Public License.
 */
 
-#include <QX11Info>
+#include <QApplication>
 #include <QMessageBox>
 
 #include "tree.h"
@@ -115,12 +115,16 @@ void tree_apply()
     g_free(p);
 
     if (!err) {
+        auto x11NativeInterface = qApp->nativeInterface<QNativeInterface::QX11Application>();
+        auto display = x11NativeInterface->display();
+        auto appRootWindow = XDefaultRootWindow(x11NativeInterface->display());
+
         XEvent ce;
 
         ce.xclient.type = ClientMessage;
-        ce.xclient.display = QX11Info::display();
+        ce.xclient.display = display;
         ce.xclient.message_type = XInternAtom(ce.xclient.display, "_OB_CONTROL", false);
-        Window root = QX11Info::appRootWindow();
+        Window root = appRootWindow;
         ce.xclient.window = root;
         ce.xclient.format = 32;
         ce.xclient.data.l[0] = 1; /* reconfigure */
