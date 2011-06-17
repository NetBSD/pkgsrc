$NetBSD: patch-.._actionpack.gemspec,v 1.5 2011/06/17 13:50:01 taca Exp $

Allow depending later version gem of builder.

--- ../actionpack-3.0.9.gemspec.orig	2011-04-06 09:18:37.000000000 +0900
+++ ../actionpack-3.0.9.gemspec	2011-04-06 09:18:37.000000000 +0900
@@ -56,7 +56,7 @@ dependencies: 
   requirement: &id003 !ruby/object:Gem::Requirement 
     none: false
     requirements: 
-    - - ~>
+    - - >=
       - !ruby/object:Gem::Version 
         hash: 15
         segments: 
