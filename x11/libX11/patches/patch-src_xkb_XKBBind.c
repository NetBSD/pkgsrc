$NetBSD: patch-src_xkb_XKBBind.c,v 1.1 2021/01/20 09:42:55 nia Exp $

Don't use pragma inside a function, it breaks compiling with older
GCCs.

XKBBind.c:230: error: #pragma GCC diagnostic not allowed inside functions

--- src/xkb/XKBBind.c.orig	2020-11-20 19:08:11.000000000 +0000
+++ src/xkb/XKBBind.c
@@ -214,6 +214,14 @@ XkbKeysymToModifiers(Display *dpy, KeySy
     return mods;
 }
 
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wdeprecated-declarations"
+#elif defined(__GNUC__)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+#endif
+
 KeySym
 XLookupKeysym(register XKeyEvent * event, int col)
 {
@@ -223,22 +231,15 @@ XLookupKeysym(register XKeyEvent * event
         return _XLookupKeysym(event, col);
     _XkbCheckPendingRefresh(dpy, dpy->xkb_info);
 
-#ifdef __clang__
-#pragma clang diagnostic push
-#pragma clang diagnostic ignored "-Wdeprecated-declarations"
-#elif defined(__GNUC__)
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
-#endif
     return XKeycodeToKeysym(dpy, event->keycode, col);
+}
+
 #ifdef __clang__
 #pragma clang diagnostic pop
 #elif defined(__GNUC__)
 #pragma GCC diagnostic pop
 #endif
 
-}
-
    /*
     * Not a public entry point -- XkbTranslateKey is an obsolete name
     * that is preserved here so that functions linked against the old
