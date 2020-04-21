$NetBSD: patch-src_baselib_dynlink__wrapper.nonatdynlink.ml,v 1.2 2020/04/21 11:51:02 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)

--- src/baselib/dynlink_wrapper.nonatdynlink.ml.orig	2018-12-19 10:54:19.000000000 +0000
+++ src/baselib/dynlink_wrapper.nonatdynlink.ml
@@ -26,8 +26,6 @@ let loadfile _ = failwith message
 
 let error_message _ = failwith message
 
-let init _ = ()
-
 let allow_unsafe_modules _ = ()
 
 let prohibit _ = ()
