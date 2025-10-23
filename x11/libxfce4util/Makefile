# $NetBSD: Makefile,v 1.84 2025/10/23 20:40:05 wiz Exp $

PKGREVISION= 4
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.20.1
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/libxfce4util/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
