$NetBSD: patch-pkg_build.ml,v 1.5 2022/05/23 15:31:34 jaapb Exp $

Do not install mime types

--- pkg/build.ml.orig	2022-03-10 16:39:39.000000000 +0000
+++ pkg/build.ml
@@ -116,8 +116,7 @@ let () =
            server_extra
     @ [ (* MISC *)
         Pkg.doc "README.md"
-      ; Pkg.doc "CHANGES"
-      ; Pkg.etc "pkg/etc/mime.types" ]
+      ; Pkg.doc "CHANGES" ]
     @ List.flatten
         (List.map
            (fun (name, files) ->
