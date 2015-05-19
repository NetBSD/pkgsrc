$NetBSD: patch-.._journey-1.0.4.gemspec,v 1.1 2015/05/19 12:30:27 ryoon Exp $

* Fix build with Ruby 2.2.

--- ../journey-1.0.4.gemspec.orig	2015-05-19 12:15:28.000000000 +0000
+++ ../journey-1.0.4.gemspec
@@ -28,14 +28,12 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<racc>, [">= 1.4.6"])
       s.add_development_dependency(%q<rdoc>, ["~> 3.11"])
       s.add_development_dependency(%q<json>, [">= 0"])
-      s.add_development_dependency(%q<rdoc>, ["~> 3.10"])
       s.add_development_dependency(%q<hoe>, ["~> 2.13"])
     else
       s.add_dependency(%q<minitest>, ["~> 2.11"])
       s.add_dependency(%q<racc>, [">= 1.4.6"])
       s.add_dependency(%q<rdoc>, ["~> 3.11"])
       s.add_dependency(%q<json>, [">= 0"])
-      s.add_dependency(%q<rdoc>, ["~> 3.10"])
       s.add_dependency(%q<hoe>, ["~> 2.13"])
     end
   else
@@ -43,7 +41,6 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<racc>, [">= 1.4.6"])
     s.add_dependency(%q<rdoc>, ["~> 3.11"])
     s.add_dependency(%q<json>, [">= 0"])
-    s.add_dependency(%q<rdoc>, ["~> 3.10"])
     s.add_dependency(%q<hoe>, ["~> 2.13"])
   end
 end
