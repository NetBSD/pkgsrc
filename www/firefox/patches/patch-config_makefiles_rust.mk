$NetBSD: patch-config_makefiles_rust.mk,v 1.6 2020/12/17 09:53:15 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

+++ config/makefiles/rust.mk
--- config/makefiles/rust.mk.orig	2020-12-03 23:12:38.000000000 +0000
+++ config/makefiles/rust.mk
@@ -52,6 +52,9 @@ endif
 ifeq (1,$(MOZ_PARALLEL_BUILD))
 cargo_build_flags += -j1
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # This should also be paired with -Zbuild-std, but that doesn't work yet.
 ifdef MOZ_TSAN
