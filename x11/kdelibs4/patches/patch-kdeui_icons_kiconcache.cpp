$NetBSD: patch-kdeui_icons_kiconcache.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- kdeui/icons/kiconcache.cpp.orig	2020-03-23 20:52:29.382360073 +0000
+++ kdeui/icons/kiconcache.cpp
@@ -103,7 +103,7 @@ public:
 KIconCache::KIconCache()
     : KPixmapCache(KDE_ICONCACHE_NAME), d(new Private(this))
 {
-    d->mUpdatesFile  = KGlobal::dirs()->locateLocal("cache", "kpc/"KDE_ICONCACHE_NAME".updated");
+    d->mUpdatesFile  = KGlobal::dirs()->locateLocal("cache", "kpc/" KDE_ICONCACHE_NAME ".updated");
     // Set limit to 10 MB
     setCacheLimit(10 * 1024);
 }
