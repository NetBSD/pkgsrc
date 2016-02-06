$NetBSD: patch-pkg_build.ml,v 1.2 2016/02/06 14:50:22 jaapb Exp $

Do not install mime types
--- pkg/build.ml.orig	2016-01-28 18:22:25.000000000 +0000
+++ pkg/build.ml
@@ -107,8 +107,7 @@ let () =
     (* MISC *)
 
     Pkg.doc "README.md";
-    Pkg.doc "CHANGES";
-    Pkg.etc "pkg/etc/mime.types"
+    Pkg.doc "CHANGES"
   ] @ (
     List.flatten (
       List.map (fun (name,files) ->
