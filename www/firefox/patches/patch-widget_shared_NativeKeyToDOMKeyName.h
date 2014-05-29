$NetBSD: patch-widget_shared_NativeKeyToDOMKeyName.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- widget/shared/NativeKeyToDOMKeyName.h.orig	2014-05-06 22:56:37.000000000 +0000
+++ widget/shared/NativeKeyToDOMKeyName.h
@@ -54,7 +54,7 @@
 #define KEY_MAP_WIN_OTH(aCPPKeyName, aNativeKey) \
   NS_OTHER_NATIVE_KEY_TO_DOM_KEY_NAME_INDEX(aNativeKey, \
                                             KEY_NAME_INDEX_##aCPPKeyName)
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #undef KEY_MAP_COCOA
 #define KEY_MAP_COCOA(aCPPKeyName, aNativeKey) \
   NS_NATIVE_KEY_TO_DOM_KEY_NAME_INDEX(aNativeKey, KEY_NAME_INDEX_##aCPPKeyName)
