# $NetBSD: Makefile,v 1.7 2004/03/28 22:06:15 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-clients-${XF_VER}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		XFree86-4.4.0-src-1.tgz XFree86-4.4.0-src-2.tgz \
			XFree86-4.4.0-src-3.tgz XFree86-4.4.0-src-4.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 client programs and related files

USE_X11=		yes
USE_BUILDLINK3=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/XFree86-libs/patches

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

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
