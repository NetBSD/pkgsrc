$NetBSD: patch-.._treetop-1.4.15.gemspec,v 1.1 2015/05/19 12:32:55 ryoon Exp $

* Fix build with Ruby 2.2.

--- ../treetop-1.4.15.gemspec.orig	2015-05-19 12:27:49.000000000 +0000
+++ ../treetop-1.4.15.gemspec
@@ -30,7 +30,6 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<rr>, ["~> 1.0"])
       s.add_development_dependency(%q<rspec>, [">= 2.0.0"])
       s.add_development_dependency(%q<rake>, [">= 0"])
-      s.add_runtime_dependency(%q<polyglot>, [">= 0.3.1"])
     else
       s.add_dependency(%q<polyglot>, [">= 0"])
       s.add_dependency(%q<jeweler>, [">= 0"])
@@ -39,7 +38,6 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<rr>, ["~> 1.0"])
       s.add_dependency(%q<rspec>, [">= 2.0.0"])
       s.add_dependency(%q<rake>, [">= 0"])
-      s.add_dependency(%q<polyglot>, [">= 0.3.1"])
     end
   else
     s.add_dependency(%q<polyglot>, [">= 0"])
@@ -49,7 +47,6 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<rr>, ["~> 1.0"])
     s.add_dependency(%q<rspec>, [">= 2.0.0"])
     s.add_dependency(%q<rake>, [">= 0"])
-    s.add_dependency(%q<polyglot>, [">= 0.3.1"])
   end
 end
 
