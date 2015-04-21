$NetBSD: patch-panel-plugin_model.c,v 1.2 2015/04/21 08:56:45 jperkin Exp $

Fix inline use.
--- panel-plugin/model.c.orig	2012-09-01 17:20:59.000000000 +0000
+++ panel-plugin/model.c
@@ -29,7 +29,7 @@
 
 /********** PlacesBookmarkAction **********/
 
-inline PlacesBookmarkAction*
+PlacesBookmarkAction*
 places_bookmark_action_create(gchar *label)
 {
     PlacesBookmarkAction *action;
@@ -40,7 +40,7 @@ places_bookmark_action_create(gchar *lab
     return action;
 }
 
-inline void
+void
 places_bookmark_action_destroy(PlacesBookmarkAction *act)
 {
     g_assert(act != NULL);
@@ -51,7 +51,7 @@ places_bookmark_action_destroy(PlacesBoo
     g_free(act);
 }
 
-inline void
+void
 places_bookmark_action_call(PlacesBookmarkAction *act)
 {
     g_assert(act != NULL);
@@ -66,7 +66,7 @@ places_bookmark_action_call(PlacesBookma
 static int bookmarks = 0;
 #endif
 
-inline PlacesBookmark*
+PlacesBookmark*
 places_bookmark_create(gchar *label)
 {
     PlacesBookmark *bookmark;
@@ -81,7 +81,7 @@ places_bookmark_create(gchar *label)
     return bookmark;
 }
 
-static inline void
+static void
 places_bookmark_actions_destroy(GList *actions)
 {
     while(actions != NULL){
@@ -92,7 +92,7 @@ places_bookmark_actions_destroy(GList *a
     g_list_free(actions);
 }
 
-inline void
+void
 places_bookmark_destroy(PlacesBookmark *bookmark)
 {
     g_assert(bookmark != NULL);
@@ -121,7 +121,7 @@ places_bookmark_destroy(PlacesBookmark *
 
 /********** PlacesBookmarkGroup **********/
 
-inline GList*
+GList*
 places_bookmark_group_get_bookmarks(PlacesBookmarkGroup *pbg)
 {
     g_assert(pbg->get_bookmarks != NULL);
@@ -129,7 +129,7 @@ places_bookmark_group_get_bookmarks(Plac
     return pbg->get_bookmarks(pbg);
 }
 
-inline gboolean
+gboolean
 places_bookmark_group_changed(PlacesBookmarkGroup *pbg)
 {
     g_assert(pbg->changed != NULL);
@@ -137,7 +137,7 @@ places_bookmark_group_changed(PlacesBook
     return pbg->changed(pbg);
 }
 
-inline PlacesBookmarkGroup*
+PlacesBookmarkGroup*
 places_bookmark_group_create(void)
 {
     PlacesBookmarkGroup *bookmark_group;
@@ -146,7 +146,7 @@ places_bookmark_group_create(void)
     return bookmark_group;
 }
 
-inline void
+void
 places_bookmark_group_destroy(PlacesBookmarkGroup *pbg)
 {
     if(pbg->finalize != NULL)
