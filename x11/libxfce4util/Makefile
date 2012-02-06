# $NetBSD: Makefile,v 1.23 2012/02/06 12:42:19 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
