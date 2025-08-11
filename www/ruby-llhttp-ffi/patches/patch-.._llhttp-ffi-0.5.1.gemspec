$NetBSD: patch-.._llhttp-ffi-0.5.1.gemspec,v 1.1 2025/08/11 11:51:08 ryoon Exp $

* Do not include Darwin/aarch64 binary files in package.

--- ../llhttp-ffi-0.5.1.gemspec.orig	2025-06-29 14:25:54.695707698 +0000
+++ ../llhttp-ffi-0.5.1.gemspec
@@ -13,7 +13,7 @@ Gem::Specification.new do |s|
   s.description = "Ruby FFI bindings for llhttp.".freeze
   s.email = "bryan@bryanp.org".freeze
   s.extensions = ["ext/Rakefile".freeze]
-  s.files = ["CHANGELOG.md".freeze, "LICENSE".freeze, "README.md".freeze, "ext/Rakefile".freeze, "ext/aarch64-darwin/libllhttp-ext.bundle".freeze, "ext/aarch64-darwin/llhttp/api.o".freeze, "ext/aarch64-darwin/llhttp/http.o".freeze, "ext/aarch64-darwin/llhttp/llhttp.o".freeze, "ext/aarch64-darwin/llhttp/llhttp_ext.o".freeze, "ext/llhttp/api.c".freeze, "ext/llhttp/extconf.rb".freeze, "ext/llhttp/http.c".freeze, "ext/llhttp/llhttp.c".freeze, "ext/llhttp/llhttp.h".freeze, "ext/llhttp/llhttp_ext.c".freeze, "lib/llhttp.rb".freeze, "lib/llhttp/delegate.rb".freeze, "lib/llhttp/error.rb".freeze, "lib/llhttp/parser.rb".freeze, "lib/llhttp/version.rb".freeze]
+  s.files = ["CHANGELOG.md".freeze, "LICENSE".freeze, "README.md".freeze, "ext/Rakefile".freeze, "ext/llhttp/api.c".freeze, "ext/llhttp/extconf.rb".freeze, "ext/llhttp/http.c".freeze, "ext/llhttp/llhttp.c".freeze, "ext/llhttp/llhttp.h".freeze, "ext/llhttp/llhttp_ext.c".freeze, "lib/llhttp.rb".freeze, "lib/llhttp/delegate.rb".freeze, "lib/llhttp/error.rb".freeze, "lib/llhttp/parser.rb".freeze, "lib/llhttp/version.rb".freeze]
   s.homepage = "https://github.com/bryanp/llhttp/".freeze
   s.licenses = ["MPL-2.0".freeze]
   s.required_ruby_version = Gem::Requirement.new(">= 2.5.0".freeze)
