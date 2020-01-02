# $NetBSD: Makefile,v 1.16 2020/01/02 22:43:42 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatekbd-${VERSION:R}.0
PKGREVISION=	2
CATEGORIES=	x11

COMMENT=	MATE keyboard configuration library

PKGCONFIG_OVERRIDE+=	libmatekbd.pc.in
PKGCONFIG_OVERRIDE+=	libmatekbdui.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
