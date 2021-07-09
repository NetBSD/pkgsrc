$NetBSD: patch-src_plugins_platforms_xcb_qxcbwindow.cpp,v 1.1 2021/07/09 22:48:47 markd Exp $

Build fixes for GCC 11

Task-number: QTBUG-89977
Change-Id: Ic1b7ddbffb8a0a00f8c621d09a868f1d94a52c21
Reviewed-by: ￼Lars Knoll <lars.knoll@qt.io>
Reviewed-by: ￼Thiago Macieira <thiago.macieira@intel.com>
(cherry picked from commit 813a928c)

--- src/plugins/platforms/xcb/qxcbwindow.cpp.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/plugins/platforms/xcb/qxcbwindow.cpp
@@ -698,7 +698,7 @@ void QXcbWindow::show()
         if (isTransient(window())) {
             const QWindow *tp = window()->transientParent();
             if (tp && tp->handle())
-                transientXcbParent = static_cast<const QXcbWindow *>(tp->handle())->winId();
+                transientXcbParent = tp->handle()->winId();
             // Default to client leader if there is no transient parent, else modal dialogs can
             // be hidden by their parents.
             if (!transientXcbParent)
