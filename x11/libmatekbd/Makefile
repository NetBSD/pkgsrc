# $NetBSD: Makefile,v 1.21 2020/08/17 20:20:28 leot Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatekbd-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE keyboard configuration library

PKGCONFIG_OVERRIDE+=	libmatekbd.pc.in
PKGCONFIG_OVERRIDE+=	libmatekbdui.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
