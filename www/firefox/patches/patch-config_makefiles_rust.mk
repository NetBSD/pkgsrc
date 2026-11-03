$NetBSD: patch-config_makefiles_rust.mk,v 1.18 2026/11/03 16:46:29 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Use less memory to fix build under NetBSD/i386.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1644409

--- config/makefiles/rust.mk.orig	2026-10-22 17:49:06.000000000 +0000
+++ config/makefiles/rust.mk
@@ -15,6 +15,9 @@ endif
 else
 normalize_sep = $(1)
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += @RUST_MAKE_JOBS@
+endif
 
 # The + prefix preserves jobserver file descriptors. Omit it for `make -n`.
 # Pass --single-job when Make is limited to one job.
