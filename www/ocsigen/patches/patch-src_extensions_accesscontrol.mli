$NetBSD: patch-src_extensions_accesscontrol.mli,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/accesscontrol.mli.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/accesscontrol.mli
@@ -20,4 +20,4 @@
 
 
 val parse_condition :
-  Simplexmlparser.xml -> Ocsigen_extensions.request_info -> bool
+  Xml.xml -> Ocsigen_extensions.request_info -> bool
