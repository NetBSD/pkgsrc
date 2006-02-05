# $NetBSD: Makefile,v 1.38 2006/02/05 23:11:25 joerg Exp $
#

PKGNAME=	links-gui-2.1.0.20
PKGREVISION=	1

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*


CONFIGURE_ARGS+=	--enable-graphics
CONFIGURE_ARGS+=	--without-sdl

.include "../../www/links/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
