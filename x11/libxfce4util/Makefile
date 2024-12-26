# $NetBSD: Makefile,v 1.78 2024/12/26 18:30:26 bsiegert Exp $

PKGREVISION=	1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfce4util-4.20.0
CATEGORIES=	x11
MASTER_SITES+=	https://archive.xfce.org/src/xfce/libxfce4util/${PKGVERSION_NOREV:R}/

COMMENT=	Xfce basic library

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
