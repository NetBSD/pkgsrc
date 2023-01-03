# $NetBSD: Makefile,v 1.66 2023/01/03 17:38:30 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.18.0
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/libxfce4util/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
