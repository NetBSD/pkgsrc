# $NetBSD: Makefile,v 1.40 2006/04/17 13:46:52 wiz Exp $
#

PKGNAME=	links-gui-2.1.0.21
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
