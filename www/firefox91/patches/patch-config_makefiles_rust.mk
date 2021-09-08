$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2021/09/08 22:19:50 nia Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2021-01-14 21:11:33.000000000 +0000
+++ config/makefiles/rust.mk
@@ -52,6 +52,9 @@ endif
 ifeq (1,$(MOZ_PARALLEL_BUILD))
 cargo_build_flags += -j1
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # We also need to rebuild the rust stdlib so that it's instrumented. Because
 # build-std is still pretty experimental, we need to explicitly request
