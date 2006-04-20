# $NetBSD: Makefile,v 1.41 2006/04/20 18:34:07 is Exp $
#

PKGNAME=	links-gui-2.1.0.21
PKGREVISION=	2

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*


CONFIGURE_ARGS+=	--enable-graphics
CONFIGURE_ARGS+=	--without-sdl

.include "../../www/links/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
