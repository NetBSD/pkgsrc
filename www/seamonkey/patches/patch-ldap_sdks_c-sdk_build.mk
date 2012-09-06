$NetBSD: patch-ldap_sdks_c-sdk_build.mk,v 1.2 2012/09/06 12:08:51 ryoon Exp $

--- ldap/sdks/c-sdk/build.mk.orig	2012-08-27 04:49:44.000000000 +0000
+++ ldap/sdks/c-sdk/build.mk
@@ -488,21 +488,21 @@ LINK_LIB        = $(RM) $@; $(AR) $(AR_F
 LINK_LIB2       = $(RM) $@; $(AR) $@ $(OBJS2); $(RANLIB) $@
 ifneq ($(LD),$(CC))
 ifdef SONAMEFLAG_PREFIX
-LINK_DLL        = $(LD) $(DSO_LDOPTS) $(LDRPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) \
+LINK_DLL        = $(LD) $(DSO_LDOPTS) $(LDRPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) $(OS_LDFLAGS) \
                         $(DLL_LDFLAGS) $(DLL_EXPORT_FLAGS) \
                         -o $@ $(SONAMEFLAG_PREFIX)$(notdir $@) $(OBJS)
 else # SONAMEFLAG_PREFIX
-LINK_DLL        = $(LD) $(DSO_LDOPTS) $(LDRPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) \
+LINK_DLL        = $(LD) $(DSO_LDOPTS) $(LDRPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) $(OS_LDFLAGS) \
                         $(DLL_LDFLAGS) $(DLL_EXPORT_FLAGS) \
                         -o $@ $(OBJS)
 endif # SONAMEFLAG_PREFIX
 else  # $(CC) is used to link libs
 ifdef SONAMEFLAG_PREFIX
-LINK_DLL        = $(LD) $(DSO_LDOPTS) $(RPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) \
+LINK_DLL        = $(LD) $(DSO_LDOPTS) $(RPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) $(OS_LDFLAGS) \
                         $(DLL_LDFLAGS) $(DLL_EXPORT_FLAGS) \
                         -o $@ $(SONAMEFLAG_PREFIX)$(notdir $@) $(OBJS)
 else # SONAMEFLAG_PREFIX
-LINK_DLL        = $(LD) $(DSO_LDOPTS) $(RPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) \
+LINK_DLL        = $(LD) $(DSO_LDOPTS) $(RPATHFLAG_PREFIX)$(RPATHFLAG) $(ALDFLAGS) $(OS_LDFLAGS) \
                         $(DLL_LDFLAGS) $(DLL_EXPORT_FLAGS) \
                         -o $@ $(OBJS)
 endif # SONAMEFLAG_PREFIX
@@ -517,7 +517,7 @@ SO_FILES_TO_REMOVE=so_locations
 endif
 
 ifneq (,$(filter BeOS Darwin NetBSD,$(OS_ARCH)))
-LINK_DLL	= $(MKSHLIB) $(OBJS)
+LINK_DLL	= $(MKSHLIB) $(OBJS) $(OS_LDFLAGS)
 endif
 
 ifeq ($(OS_ARCH), HP-UX)
