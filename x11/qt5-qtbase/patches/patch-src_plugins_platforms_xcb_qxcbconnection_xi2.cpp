$NetBSD: patch-src_plugins_platforms_xcb_qxcbconnection_xi2.cpp,v 1.1 2015/04/03 09:28:20 mrg Exp $

handle earlier Xinput versions.

--- src/plugins/platforms/xcb/qxcbconnection_xi2.cpp.orig	2015-04-03 00:37:14.000000000 -0700
+++ src/plugins/platforms/xcb/qxcbconnection_xi2.cpp	2015-04-03 00:35:27.000000000 -0700
@@ -175,9 +175,11 @@
             case XIKeyClass:
                 qCDebug(lcQpaXInputDevices) << "   it's a keyboard";
                 break;
+#ifdef XITouchClass
             case XITouchClass:
                 // will be handled in deviceForId()
                 break;
+#endif
             default:
                 qCDebug(lcQpaXInputDevices) << "   has class" << devices[i].classes[c]->type;
                 break;
