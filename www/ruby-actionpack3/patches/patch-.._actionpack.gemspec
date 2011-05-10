$NetBSD: patch-.._actionpack.gemspec,v 1.3 2011/05/10 14:12:06 taca Exp $

Allow depending later version gem of builder.

--- ../actionpack-3.0.7.gemspec.orig	2011-04-06 09:18:37.000000000 +0900
+++ ../actionpack-3.0.7.gemspec	2011-04-06 09:18:37.000000000 +0900
@@ -56,7 +56,7 @@ dependencies: 
   requirement: &id003 !ruby/object:Gem::Requirement 
     none: false
     requirements: 
-    - - ~>
+    - - >=
       - !ruby/object:Gem::Version 
         hash: 15
         segments: 
