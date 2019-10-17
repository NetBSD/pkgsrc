$NetBSD: patch-.._jekyll-4.0.0.gemspec,v 1.1 2019/10/17 16:13:17 taca Exp $

Allow lower rubygems, Ruby 2.4.

--- ../jekyll-4.0.0.gemspec.orig	2019-10-16 16:07:46.095067718 +0000
+++ ../jekyll-4.0.0.gemspec
@@ -5,7 +5,7 @@ Gem::Specification.new do |s|
   s.name = "jekyll".freeze
   s.version = "4.0.0"
 
-  s.required_rubygems_version = Gem::Requirement.new(">= 2.7.0".freeze) if s.respond_to? :required_rubygems_version=
+  s.required_rubygems_version = Gem::Requirement.new(">= 2.6.0".freeze) if s.respond_to? :required_rubygems_version=
   s.metadata = { "bug_tracker_uri" => "https://github.com/jekyll/jekyll/issues", "changelog_uri" => "https://github.com/jekyll/jekyll/releases", "homepage_uri" => "https://jekyllrb.com", "source_code_uri" => "https://github.com/jekyll/jekyll" } if s.respond_to? :metadata=
   s.require_paths = ["lib".freeze]
   s.authors = ["Tom Preston-Werner".freeze, "Parker Moore".freeze, "Matt Rogers".freeze]
