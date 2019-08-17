# $NetBSD: Makefile,v 1.57 2019/08/17 18:32:33 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.14.0
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/libxfce4util/4.14/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
