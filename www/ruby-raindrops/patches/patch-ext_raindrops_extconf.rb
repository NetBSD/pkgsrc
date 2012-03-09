$NetBSD: patch-ext_raindrops_extconf.rb,v 1.1 2012/03/09 13:29:58 fhajny Exp $

Avoid stumbling upon -march=i486.
--- ext/raindrops/extconf.rb.orig	2012-02-27 22:41:38.588175948 +0000
+++ ext/raindrops/extconf.rb
@@ -23,13 +23,6 @@ int main(int argc, char * const argv[]) 
 SRC
 
   if try_run(src)
-    # some systems target GCC for i386 and don't get the atomic builtins
-    # when building shared objects
-    arch = `#{CONFIG['CC']} -dumpmachine`.split(/-/)[0]
-    if arch == "i386" && $CFLAGS !~ /\b-march=/
-      $CFLAGS += " -march=i486 "
-    end
-
     $defs.push(format("-DHAVE_GCC_ATOMIC_BUILTINS"))
     true
   else
