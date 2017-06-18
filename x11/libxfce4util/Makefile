# $NetBSD: Makefile,v 1.44 2017/06/18 21:22:08 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.13.0
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/libxfce4util/4.13/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
