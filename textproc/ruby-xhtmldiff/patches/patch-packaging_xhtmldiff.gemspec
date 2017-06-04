$NetBSD: patch-packaging_xhtmldiff.gemspec,v 1.1 2017/06/04 16:49:36 taca Exp $

Fix versuion in gemspec.

--- packaging/xhtmldiff.gemspec.orig	2006-09-07 00:15:50.000000000 +0000
+++ packaging/xhtmldiff.gemspec
@@ -1,6 +1,6 @@
 Gem::Specification.new do |s|
   s.name = %q{xhtmldiff}
-  s.version = "1.0.0"
+  s.version = "1.2.2"
   s.date = Time.now
   s.summary = %q{XHTMLDiff is a tool and library for taking valid XHTML documents as input, and generating redlined valid XHTML text highlighting the changes between them as output.}
   s.author = %q{Aredridel}
