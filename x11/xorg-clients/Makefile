# $NetBSD: Makefile,v 1.6 2004/10/04 12:32:19 hira Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-clients-${XORG_VER}
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES=		X11R${XORG_VER}-src1.tar.gz \
			X11R${XORG_VER}-src2.tar.gz \
			X11R${XORG_VER}-src3.tar.gz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org client programs and related files

USE_X11=		yes
USE_BUILDLINK3=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

post-buildlink:
	@${MKDIR} ${WRKSRC}/exports/include
	@${CP} ${X11ROOT}/include/X11/fonts/*.h ${BUILDLINK_DIR}/include

post-configure:
	@${MKDIR} ${WRKSRC}/exports/lib
	@${CP} ${X11ROOT}/lib/lib* ${WRKSRC}/exports/lib

post-install:
	@${CHMOD} a+r ${X11ROOT}/bin/xterm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../security/PAM/buildlink3.mk"
.endif

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
