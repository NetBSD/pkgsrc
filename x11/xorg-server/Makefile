# $NetBSD: Makefile,v 1.32 2006/01/23 22:55:16 joerg Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-server-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R${XORG_VER}-src1.tar.gz \
		X11R${XORG_VER}-src2.tar.gz \
		X11R${XORG_VER}-src3.tar.gz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org X server and related programs

DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau \
			programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font/FreeType \
			lib/font/Type1 \
			lib/font/bitmap programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
XORG_PLIST_ENTRY=	${OPSYS}

REPLACE_PERL=		exports/lib/modules/getconfig*

SUBST_CLASSES+=		parser
SUBST_STAGE.parser=	pre-install
SUBST_FILES.parser=	programs/Xserver/hw/xfree86/parser/Makefile
SUBST_SED.parser=	-e '/$$(INSTALL).*lib$$(LIBNAME).a/ d'
SUBST_SED.parser+=	-e '/$$(RANLIB).*lib$$(LIBNAME).a/ d'
SUBST_SED.parser+=	-e 's|$$(INSTALL) $$(INSTALLFLAGS) $$(INSTINCFLAGS)|echo|'
SUBST_MESSAGE.parser=	"Fixing parser Makefile."

SUBST_CLASSES+=		stubs
SUBST_STAGE.stubs=	pre-install
SUBST_FILES.stubs=	lib/font/stubs/Makefile
SUBST_SED.stubs=	-e '/$$(INSTALL).*libfntstubs.a/ d'
SUBST_SED.stubs+=	-e '/$$(RANLIB).*libfntstubs.a/ d'
SUBST_MESSAGE.stubs=	"Fixing stubs Makefile."

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	perl	# Yeah, we need this :-)
.endif

.if ${OPSYS} == "Darwin"
BUILDLINK_PASSTHRU_DIRS+=	/System
.else
.include "options.mk"
.endif

.if ${MACHINE_ARCH} == "i386" || \
    (${OPSYS} == "NetBSD" && \
    (${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "powerpc"))
PLIST_SUBST+=	SCANPCI=
.else
PLIST_SUBST+=	SCANPCI='@comment '
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "alpha" || \
    ${MACHINE_ARCH} == "ia64" || ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	IOPORT=
.else
PLIST_SUBST+=	IOPORT='@comment '
.endif

post-install:
	@${SED} ${XORG_PLIST_SED} ${PKGDIR}/PLIST > ${PLIST_SRC}
.if ${OPSYS} == "Darwin"
	${CHMOD} a+r ${X11ROOT}/bin/XDarwin
.else
	${CHMOD} a+r ${X11ROOT}/bin/Xorg
.endif

.if ${OPSYS} == "Linux"
.  include "../../x11/Xrender/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
