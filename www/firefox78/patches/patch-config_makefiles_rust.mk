$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2020/07/30 08:09:28 nia Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2020-04-03 19:34:34.000000000 +0000
+++ config/makefiles/rust.mk
@@ -52,6 +52,9 @@ endif
 ifeq (1,$(MOZ_PARALLEL_BUILD))
 cargo_build_flags += -j1
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # These flags are passed via `cargo rustc` and only apply to the final rustc
 # invocation (i.e., only the top-level crate, not its dependencies).
