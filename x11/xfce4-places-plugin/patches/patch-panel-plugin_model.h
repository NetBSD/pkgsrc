$NetBSD: patch-panel-plugin_model.h,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/model.h.orig	2007-10-25 22:03:52.000000000 +0000
+++ panel-plugin/model.h
@@ -35,10 +35,10 @@ struct _PlacesBookmarkAction
 
 };
 
-inline void
+void
 places_bookmark_action_call(PlacesBookmarkAction*);
 
-inline void
+void
 places_bookmark_action_free(PlacesBookmarkAction*);
 
 /* Places Bookmark */
@@ -65,10 +65,10 @@ struct _PlacesBookmark
     void                 (*free) (PlacesBookmark *self);
 };
 
-inline PlacesBookmark*
+PlacesBookmark*
 places_bookmark_create(gchar *label);
 
-inline void
+void
 places_bookmark_free(PlacesBookmark *bookmark);
 
 /* Places Bookmark Group */
@@ -81,13 +81,13 @@ struct _PlacesBookmarkGroup
     gpointer    priv;
 };
 
-inline GList*
+GList*
 places_bookmark_group_get_bookmarks(PlacesBookmarkGroup*);
 
-inline gboolean
+gboolean
 places_bookmark_group_changed(PlacesBookmarkGroup*);
 
-inline void
+void
 places_bookmark_group_finalize(PlacesBookmarkGroup*);
 
 #endif
