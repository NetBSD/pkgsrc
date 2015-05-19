$NetBSD: patch-.._tilt-1.4.1.gemspec,v 1.1 2015/05/19 12:31:26 ryoon Exp $

* Fix build with Ruby 2.2.

--- ../tilt-1.4.1.gemspec.orig	2015-05-19 12:24:21.000000000 +0000
+++ ../tilt-1.4.1.gemspec
@@ -46,7 +46,6 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<sass>, [">= 0"])
       s.add_development_dependency(%q<wikicloth>, [">= 0"])
       s.add_development_dependency(%q<yajl-ruby>, [">= 0"])
-      s.add_development_dependency(%q<rdoc>, [">= 0"])
     else
       s.add_dependency(%q<asciidoctor>, [">= 0.1.0"])
       s.add_dependency(%q<RedCloth>, [">= 0"])
@@ -70,7 +69,6 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<sass>, [">= 0"])
       s.add_dependency(%q<wikicloth>, [">= 0"])
       s.add_dependency(%q<yajl-ruby>, [">= 0"])
-      s.add_dependency(%q<rdoc>, [">= 0"])
     end
   else
     s.add_dependency(%q<asciidoctor>, [">= 0.1.0"])
@@ -95,7 +93,6 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<sass>, [">= 0"])
     s.add_dependency(%q<wikicloth>, [">= 0"])
     s.add_dependency(%q<yajl-ruby>, [">= 0"])
-    s.add_dependency(%q<rdoc>, [">= 0"])
   end
 end
 
