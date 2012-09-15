# $NetBSD: Makefile,v 1.26 2012/09/15 10:07:10 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
PKGREVISION=	9
CATEGORIES=	x11
COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
