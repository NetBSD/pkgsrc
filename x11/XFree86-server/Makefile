# $NetBSD: Makefile,v 1.5 2004/02/04 23:56:29 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-server-${XF_VER}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		X430src-1.tgz X430src-2.tgz \
			X430src-3.tgz X430src-4.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 X server and related programs

USE_IMAKE=		yes
USE_BUILDLINK2=		yes
DISTINFO_FILE=		${.CURDIR}/../XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../XFree86-libs/patches

XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau \
			programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_MANNEWSUFFIX}
PLIST_SUBST+=		MANPAGE_LIB_SUFFIX=${IMAKE_MANNEWSUFFIX}
.else
PLIST_SUBST+=		MANPAGE_LIB_SUFFIX=${IMAKE_FILEMAN_SUFFIX}
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_LIBMAN_SUFFIX}
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PLIST_SUBST+=		DRIMODULES=
USE_PERL5=		yes # Still we need perl (at least for now)
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "alpha"
XBUILD_DIRS+=		lib/XThrStub lib/X11 lib/Xext lib/GL
XINSTALL_DIRS+=		lib/GL/mesa/src/drv
.  endif
.else
PLIST_SUBST+=		LIBDRI="@comment "
PLIST_SUBST+=		DRIMODULES="@comment "
.endif

.if ${OPSYS} == "Linux"
PLIST_SUBST+=		KBDMODE="@comment "
.else
PLIST_SUBST+=		KBDMODE=
.endif

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=		LIBDRI=
.endif

pre-install:
	@cd ${WRKSRC}/programs/Xserver/hw/xfree86/parser && \
		${CP} Makefile Makefile.orig && \
		${SED} -e '/$$(INSTALL).*lib$$(LIBNAME).a/ d' \
		-e '/$$(RANLIB).*lib$$(LIBNAME).a/ d' \
		-e 's|$$(INSTALL) $$(INSTALLFLAGS) $$(INSTINCFLAGS)|echo|' \
		Makefile.orig > Makefile
	@cd ${WRKSRC}/lib/font/stubs && \
		${CP} Makefile Makefile.orig && \
		${SED} -e '/$$(INSTALL).*libfntstubs.a/ d' \
			-e '/$$(RANLIB).*libfntstubs.a/ d' Makefile.orig \
			> Makefile

.include "../../devel/zlib/buildlink2.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../x11/XFree86-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
