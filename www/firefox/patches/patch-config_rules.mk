$NetBSD: patch-config_rules.mk,v 1.5 2017/08/10 14:46:15 ryoon Exp $

--- config/rules.mk.orig	2017-07-31 16:20:50.000000000 +0000
+++ config/rules.mk
@@ -900,6 +900,7 @@ endif
 
 $(foreach file,$(DUMP_SYMS_TARGETS),$(eval $(call syms_template,$(file),$(file)_syms.track)))
 
+ifdef MOZ_RUST
 cargo_host_flag := --target=$(RUST_HOST_TARGET)
 cargo_target_flag := --target=$(RUST_TARGET)
 
@@ -1055,6 +1056,7 @@ force-cargo-host-program-build:
 
 $(HOST_RUST_PROGRAMS): force-cargo-host-program-build
 endif # HOST_RUST_PROGRAMS
+endif # MOZ_RUST
 
 $(SOBJS):
 	$(REPORT_BUILD)
