$NetBSD: patch-lib_libxview_notice_notice__ol.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/notice/notice_ol.c.orig	2012-11-14 14:14:32.000000000 +0000
+++ lib/libxview/notice/notice_ol.c
@@ -37,7 +37,7 @@ Xv_private void		win_change_property();
 /*
  * Public routines - these routines are private to the notice pkg
  */
-Pkg_private int		notice_subframe_layout();
+Pkg_private void	notice_subframe_layout();
 Pkg_private int		notice_determine_font();
 Pkg_private void	notice_draw_borders();
 Pkg_private int		notice_center();
@@ -82,7 +82,7 @@ Notice_config	Notice_dimensions[] = {
 /*
  * Routine to create sub_frame and panels
  */
-Pkg_private int
+Pkg_private void
 notice_subframe_layout(notice, do_msg, do_butt)
 Notice_info	*notice;
 Bool		do_msg;
