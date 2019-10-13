$NetBSD: patch-common.mk,v 1.1 2019/10/13 21:48:58 he Exp $

Add to CFLAGS_COMMON and CXXFLAGS_COMMON, omit debug and optimize flags.
Use libtool to install.

--- common.mk.orig	2019-09-25 23:16:12.000000000 +0000
+++ common.mk
@@ -48,15 +48,15 @@ GCC_CXX_WARNINGS = $(GCC_WARNINGS)  -Wsy
 # assertion and crash the program if it isn't really true.  You can add
 # -UNDEBUG (in any of various ways) to override this.
 #
-CFLAGS_COMMON = -DNDEBUG $(CFLAGS_PTHREAD)
-CXXFLAGS_COMMON = -DNDEBUG $(CFLAGS_PTHREAD)
+CFLAGS_COMMON += -DNDEBUG $(CFLAGS_PTHREAD)
+CXXFLAGS_COMMON += -DNDEBUG $(CFLAGS_PTHREAD)
 
 ifeq ($(C_COMPILER_GNU),yes)
-  CFLAGS_COMMON += $(GCC_C_WARNINGS) -fno-common -g -O3
+  CFLAGS_COMMON += $(GCC_C_WARNINGS) -fno-common
 endif
 
 ifeq ($(CXX_COMPILER_GNU),yes)
-  CXXFLAGS_COMMON += $(GCC_CXX_WARNINGS) -g
+  CXXFLAGS_COMMON += $(GCC_CXX_WARNINGS)
 endif
 
 # -qrtti tell the IBM compilers to allow dynamic type casting.  Without it,
@@ -629,7 +629,7 @@ install-headers: $(HEADERS_TO_INSTALL)
 	   $(INSTALL_HDR_CMD); \
 	 done
 
-INSTALL_PROGRAM_CMD = $(INSTALL_PROGRAM) $$p $(PROGRAMDESTDIR)/$$p
+INSTALL_PROGRAM_CMD = libtool --mode=install $(INSTALL_PROGRAM) $$p $(PROGRAMDESTDIR)/$$p
 
 install-bin: $(PROGRAMS_TO_INSTALL) $(DESTDIR)$(PROGRAMINST_DIR)
 	@list='$(PROGRAMS_TO_INSTALL)'; \
