$NetBSD: patch-build_common__library.rb,v 1.1 2018/01/30 12:06:48 fhajny Exp $

Fix libev configure on Illumos.

--- build/common_library.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ build/common_library.rb
@@ -142,7 +142,7 @@ if USE_VENDORED_LIBEV
       "--disable-shared --enable-static " +
       # libev's configure script may select a different default compiler than we
       # do, so we force our compiler choice.
-      "CC='#{cc_command}' CXX='#{cxx_command}' CFLAGS='#{cflags}' orig_CFLAGS=1"
+      "CC='#{cc_command}' CXX='#{cxx_command}' CFLAGS='#{cflags}' orig_CFLAGS=1 #{ENV['LIBEV_EXTRA_ARGS']}"
   end
 
   libev_sources = Dir["src/cxx_supportlib/vendor-modified/libev/{*.c,*.h}"]
