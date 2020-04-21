$NetBSD: patch-pkg_build.ml,v 1.4 2020/04/21 12:52:06 jaapb Exp $

Do not install mime types

--- pkg/build.ml.orig	2020-03-11 10:55:00.000000000 +0000
+++ pkg/build.ml
@@ -104,7 +104,6 @@ let () =
 
     Pkg.doc "README.md";
     Pkg.doc "CHANGES";
-    Pkg.etc "pkg/etc/mime.types"
   ] @ (
     List.flatten (
       List.map (fun (name,files) ->
