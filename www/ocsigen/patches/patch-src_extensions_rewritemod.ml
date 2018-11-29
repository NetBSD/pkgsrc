$NetBSD: patch-src_extensions_rewritemod.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/rewritemod.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/rewritemod.ml
@@ -44,7 +44,6 @@
 
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 
 let section = Lwt_log.Section.make "ocsigen:ext:rewritemod"
 
