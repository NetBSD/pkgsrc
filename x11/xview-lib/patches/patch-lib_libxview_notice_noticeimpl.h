$NetBSD: patch-lib_libxview_notice_noticeimpl.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/notice/noticeimpl.h.orig	2012-11-14 14:14:29.000000000 +0000
+++ lib/libxview/notice/noticeimpl.h
@@ -185,7 +185,7 @@ Pkg_private void			notice_build_button()
 Pkg_private void			notice_button_panel_proc();
 Pkg_private int				notice_determine_font();
 Pkg_private int				notice_center();
-Pkg_private int				notice_subframe_layout();
+Pkg_private void			notice_subframe_layout();
 Pkg_private int				notice_text_width();
 Pkg_private int				notice_button_width();
 Pkg_private int				notice_get_owner_frame();
