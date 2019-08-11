# $NetBSD: Makefile,v 1.56 2019/08/11 13:25:13 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.13.4
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/libxfce4util/4.13/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
