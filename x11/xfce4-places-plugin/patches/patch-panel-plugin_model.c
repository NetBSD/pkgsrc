$NetBSD: patch-panel-plugin_model.c,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/model.c.orig	2007-10-25 22:03:52.000000000 +0000
+++ panel-plugin/model.c
@@ -27,7 +27,7 @@
 
 #include <libxfce4util/libxfce4util.h>
 
-inline void
+void
 places_bookmark_action_call(PlacesBookmarkAction *act)
 {
     g_assert(act != NULL);
@@ -36,7 +36,7 @@ places_bookmark_action_call(PlacesBookma
         act->action(act);
 }
 
-inline void
+void
 places_bookmark_action_free(PlacesBookmarkAction *act)
 {
     g_assert(act != NULL);
@@ -62,7 +62,7 @@ places_bookmark_actions_free(GList *acti
 static int bookmarks = 0;
 #endif
 
-inline PlacesBookmark*
+PlacesBookmark*
 places_bookmark_create(gchar *label)
 {
     PlacesBookmark *bookmark;
@@ -77,7 +77,7 @@ places_bookmark_create(gchar *label)
     return bookmark;
 }
 
-inline void
+void
 places_bookmark_free(PlacesBookmark *bookmark)
 {
     g_assert(bookmark != NULL);
@@ -104,19 +104,19 @@ places_bookmark_free(PlacesBookmark *boo
         g_free(bookmark);
 }
 
-inline GList*
+GList*
 places_bookmark_group_get_bookmarks(PlacesBookmarkGroup *pbg)
 {
     return pbg->get_bookmarks(pbg);
 }
 
-inline gboolean
+gboolean
 places_bookmark_group_changed(PlacesBookmarkGroup *pbg)
 {
     return pbg->changed(pbg);
 }
 
-inline void
+void
 places_bookmark_group_finalize(PlacesBookmarkGroup *pbg)
 {
     pbg->finalize(pbg);
