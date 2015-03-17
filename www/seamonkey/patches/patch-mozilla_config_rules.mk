$NetBSD: patch-mozilla_config_rules.mk,v 1.3 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/config/rules.mk.orig	2015-03-09 05:34:34.000000000 +0000
+++ mozilla/config/rules.mk
@@ -765,6 +765,7 @@ endif
 ifdef DTRACE_PROBE_OBJ
 EXTRA_DEPS += $(DTRACE_PROBE_OBJ)
 OBJS += $(DTRACE_PROBE_OBJ)
+EXCLUDED_OBJS += $(DTRACE_PROBE_OBJ)
 endif
 
 $(filter %.$(LIB_SUFFIX),$(LIBRARY)): $(OBJS) $(STATIC_LIBS_DEPS) $(filter %.$(LIB_SUFFIX),$(EXTRA_LIBS)) $(EXTRA_DEPS) $(GLOBAL_DEPS)
