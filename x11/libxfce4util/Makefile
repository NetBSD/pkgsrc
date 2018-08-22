# $NetBSD: Makefile,v 1.49 2018/08/22 09:48:02 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.13.1
CATEGORIES=	x11
MASTER_SITES+=	http://archive.xfce.org/src/xfce/libxfce4util/4.13/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
