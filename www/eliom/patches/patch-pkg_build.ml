$NetBSD: patch-pkg_build.ml,v 1.1 2015/02/11 15:30:13 jaapb Exp $

Do not install mime types
--- pkg/build.ml.orig	2014-10-01 15:19:35.000000000 +0000
+++ pkg/build.ml
@@ -96,8 +96,7 @@ let () =
     (* MISC *)
 
     Pkg.doc "README";
-    Pkg.doc "CHANGES";
-    Pkg.etc "pkg/etc/mime.types"
+    Pkg.doc "CHANGES"
   ] @ (
     List.flatten (
       List.map (fun (name,files) ->
