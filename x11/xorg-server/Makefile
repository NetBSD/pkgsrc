# $NetBSD: Makefile,v 1.9 2004/10/08 03:35:25 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-server-${XORG_VER}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES=		X11R${XORG_VER}-src1.tar.gz \
			X11R${XORG_VER}-src2.tar.gz \
			X11R${XORG_VER}-src3.tar.gz		

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org X server and related programs

USE_X11=		yes
USE_BUILDLINK3=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau \
			programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font/FreeType \
			lib/font/Type1 \
			lib/font/bitmap programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

REPLACE_PERL=		exports/lib/modules/getconfig*

SUBST_CLASSES=		parser
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
USE_PERL5=	build # Yeah, we need this :-)
.endif

post-install:
	${CHMOD} a+r ${X11ROOT}/bin/Xorg

.if ${OPSYS} == "Linux"
.  include "../../x11/Xrender/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
