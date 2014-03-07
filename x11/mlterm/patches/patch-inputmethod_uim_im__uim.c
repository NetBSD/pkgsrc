$NetBSD: patch-inputmethod_uim_im__uim.c,v 1.1 2014/03/07 18:22:50 tsutsui Exp $

Pull mlterm-3.3.3-fixes.patch from upstream:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.3/mlterm-3.3.3-fixes.patch/download
 - Hack for uim-mozc is added

--- inputmethod/uim/im_uim.c.orig	2014-02-21 16:51:46.000000000 +0000
+++ inputmethod/uim/im_uim.c
@@ -78,6 +78,8 @@ typedef struct im_uim
 
 	u_int  cand_limit ;
 
+	int  is_mozc ;
+
 }  im_uim_t ;
 
 KIK_LIST_TYPEDEF( im_uim_t) ;
@@ -744,13 +746,13 @@ candidate_activate(
 
 	uim = (im_uim_t*) p ;
 
+	(*uim->im.listener->get_spot)( uim->im.listener->self ,
+				       uim->im.preedit.chars ,
+				       uim->im.preedit.segment_offset ,
+				       &x , &y) ;
+
 	if( uim->im.cand_screen == NULL)
 	{
-		(*uim->im.listener->get_spot)( uim->im.listener->self ,
-					       uim->im.preedit.chars ,
-					       uim->im.preedit.segment_offset ,
-					       &x , &y) ;
-
 		if( ! ( uim->im.cand_screen = (*syms->x_im_candidate_screen_new)(
 				uim->im.disp , uim->im.font_man , uim->im.color_man ,
 				(*uim->im.listener->is_vertical)(uim->im.listener->self) ,
@@ -847,6 +849,22 @@ candidate_select(
 
 	if( uim->im.cand_screen)
 	{
+		/*
+		 * XXX Hack for uim-mozc (1.11.1522.102)
+		 * If candidate_activate() is called with num == 20 and limit = 10,
+		 * uim_get_candidate() on mozc doesn't returns 20 candidates but 10 ones.
+		 * (e.g. uim_get_candidate(0) and uim_get_candidate(10) returns the same.)
+		 */
+		if( uim->is_mozc &&
+		    uim->im.cand_screen->index != index &&
+		    uim->im.cand_screen->index / uim->cand_limit != index / uim->cand_limit &&
+		    (index % uim->cand_limit) == 0)
+		{
+			candidate_activate( p ,
+				uim->im.cand_screen->num_of_candidates ,
+				uim->cand_limit) ;
+		}
+
 		(*uim->im.cand_screen->select)( uim->im.cand_screen , index) ;
 	}
 }
@@ -1616,6 +1634,8 @@ im_uim_new(
 		goto  error ;
 	}
 
+	uim->is_mozc = (strcmp( engine , "mozc") == 0) ;
+
 	uim_set_preedit_cb( uim->context ,
 			    preedit_clear ,
 			    preedit_pushback ,
