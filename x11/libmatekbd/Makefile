# $NetBSD: Makefile,v 1.32 2023/01/29 21:18:13 ryoon Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmatekbd-${VERSION}
CATEGORIES=	x11

COMMENT=	MATE keyboard configuration library

PKGCONFIG_OVERRIDE+=	libmatekbd.pc.in
PKGCONFIG_OVERRIDE+=	libmatekbdui.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
