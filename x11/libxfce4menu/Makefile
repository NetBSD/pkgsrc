# $NetBSD: Makefile,v 1.8 2012/03/03 00:12:05 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4menu-${XFCE4_VERSION}
PKGREVISION=	7
CATEGORIES=	x11
COMMENT=	Xfce menu library

PKGCONFIG_OVERRIDE+=	libxfce4menu/libxfce4menu-0.1.pc

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
