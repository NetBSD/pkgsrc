# $NetBSD: hacks.mk,v 1.1 2012/09/25 08:07:31 apb Exp $

### [Sat Sep 22 11:21:06 UTC 2012 : apb]
### g++-4.5.3 and 4.5.4 on NetBSD/i386 fails with an internal compiler error
### when building gui/painting/qdrawhelper_mmx.cpp.
### Building with -O1 instead of -O2 seems to work around the problem.
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.5.*)
PKG_HACKS+=		pr46978
SUBST_CLASSES+=		pr46978
SUBST_STAGE.pr46978=	post-configure
SUBST_MESSAGE.pr46978=	Working around optimizer bug (NetBSD PR 46978)
SUBST_FILES.pr46978=	src/gui/Makefile
SUBST_SED.pr46978=	-e '/^CXXFLAGS/s/-O2/-O1/'
.  endif
.endif
