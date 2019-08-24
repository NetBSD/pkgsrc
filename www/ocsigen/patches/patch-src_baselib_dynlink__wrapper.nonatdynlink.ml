$NetBSD: patch-src_baselib_dynlink__wrapper.nonatdynlink.ml,v 1.1 2019/08/24 11:13:48 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)
--- src/baselib/dynlink_wrapper.nonatdynlink.ml.orig	2018-12-19 10:54:19.000000000 +0000
+++ src/baselib/dynlink_wrapper.nonatdynlink.ml
@@ -26,8 +26,6 @@ let loadfile _ = failwith message
 
 let error_message _ = failwith message
 
-let init _ = ()
-
 let allow_unsafe_modules _ = ()
 
 let prohibit _ = ()
