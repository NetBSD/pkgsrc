$NetBSD: patch-src_desktops.cpp,v 1.1 2024/08/18 07:44:23 pin Exp $

Port to Qt6.

--- src/desktops.cpp.orig	2024-01-14 11:02:54.000000000 +0000
+++ src/desktops.cpp
@@ -20,11 +20,11 @@
     51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
 
+#include <QApplication>
 #include "maindialog.h"
 #include <obrender/render.h>
 #include "tree.h"
 
-#include <QX11Info>
 #include <X11/Xlib.h>
 
 using namespace Obconf;
@@ -123,26 +123,37 @@ void MainDialog::desktops_write_names() 
   }
 
   tree_apply();
+
+  auto x11NativeInterface = qApp->nativeInterface<QNativeInterface::QX11Application>();
+  auto display = x11NativeInterface->display();
+  auto appRootWindow = XDefaultRootWindow(x11NativeInterface->display());
+
   /* make openbox re-set the property */
-  XDeleteProperty(QX11Info::display(), QX11Info::appRootWindow(),
-                  XInternAtom(QX11Info::display(), "_NET_DESKTOP_NAMES", False));
+  XDeleteProperty(display, appRootWindow,
+                  XInternAtom(display, "_NET_DESKTOP_NAMES", False));
 }
 
 void MainDialog::desktops_write_number() {
+
+  auto x11NativeInterface = qApp->nativeInterface<QNativeInterface::QX11Application>();
+  auto display = x11NativeInterface->display();
+  auto appRootWindow = XDefaultRootWindow(x11NativeInterface->display());
+
   XEvent ce;
   tree_set_int("desktops/number", num_desktops);
   ce.xclient.type = ClientMessage;
   ce.xclient.message_type =
-    XInternAtom(QX11Info::display(), "_NET_NUMBER_OF_DESKTOPS", False);
-  ce.xclient.display = QX11Info::display();
-  ce.xclient.window = QX11Info::appRootWindow();
+    XInternAtom(display, "_NET_NUMBER_OF_DESKTOPS", False);
+  ce.xclient.display = display;
+  ce.xclient.window = appRootWindow;
   ce.xclient.format = 32;
   ce.xclient.data.l[0] = num_desktops;
   ce.xclient.data.l[1] = 0;
   ce.xclient.data.l[2] = 0;
   ce.xclient.data.l[3] = 0;
   ce.xclient.data.l[4] = 0;
-  XSendEvent(QX11Info::display(), QX11Info::appRootWindow(), FALSE,
+
+  XSendEvent(display, appRootWindow, FALSE,
              SubstructureNotifyMask | SubstructureRedirectMask,
              &ce);
 }
