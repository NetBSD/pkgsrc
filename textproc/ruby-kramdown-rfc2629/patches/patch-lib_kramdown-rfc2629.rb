$NetBSD: patch-lib_kramdown-rfc2629.rb,v 1.1 2021/01/17 17:26:15 riastradh Exp $

Make this work with kramdown 2.x, which is what we have in pkgsrc.
This seems to work fine, and certainly better than trying to use 1.17.0
which fails on startup.

--- lib/kramdown-rfc2629.rb.orig	2021-01-16 21:48:50.361415982 +0000
+++ lib/kramdown-rfc2629.rb
@@ -12,7 +12,7 @@ require 'shellwords'
 
 raise "sorry, 1.8 was last decade" unless RUBY_VERSION >= '1.9'
 
-gem 'kramdown', '~> 1.17.0'
+gem 'kramdown', '~> 2.0'
 require 'kramdown'
 my_span_elements =  %w{list figure xref eref iref cref spanx vspace}
 Kramdown::Parser::Html::Constants::HTML_SPAN_ELEMENTS.concat my_span_elements
