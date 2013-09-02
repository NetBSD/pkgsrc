# $NetBSD: Makefile,v 1.18 2013/09/02 19:50:48 adam Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4menu-${XFCE4_VERSION}
PKGREVISION=	16
CATEGORIES=	x11
COMMENT=	Xfce menu library

PKGCONFIG_OVERRIDE+=	libxfce4menu/libxfce4menu-0.1.pc

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
