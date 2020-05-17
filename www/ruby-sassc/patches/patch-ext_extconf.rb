$NetBSD: patch-ext_extconf.rb,v 1.3 2020/05/17 16:25:42 taca Exp $

Don't enable host-specific optimisations.
Don't enable LTO.

--- ext/extconf.rb.orig	2020-04-25 02:39:24.087193330 +0000
+++ ext/extconf.rb
@@ -19,22 +19,11 @@ if enable_config('static-stdlib', false)
   $LDFLAGS << ' -static-libgcc -static-libstdc++'
 end
 
-if enable_config('march-tune-native', false)
-  $CFLAGS << ' -march=native -mtune=native'
-  $CXXFLAGS << ' -march=native -mtune=native'
-end
-
 # darwin nix clang doesn't support lto
 # disable -lto flag for darwin + nix
 # see: https://github.com/sass/sassc-ruby/issues/148
 enable_lto_by_default = (Gem::Platform.local.os == "darwin" && !ENV['NIX_CC'].nil?)
 
-if enable_config('lto', enable_lto_by_default)
-  $CFLAGS << ' -flto'
-  $CXXFLAGS << ' -flto'
-  $LDFLAGS << ' -flto'
-end
-
 # Disable noisy compilation warnings.
 $warnflags = ''
 $CFLAGS.gsub!(/[\s+](-ansi|-std=[^\s]+)/, '')
