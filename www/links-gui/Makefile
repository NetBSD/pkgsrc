# $NetBSD: Makefile,v 1.28 2004/03/26 02:27:57 wiz Exp $
#

PKGNAME=	links-gui-2.1.0.14
PKGREVISION=	2

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*

USE_X11=	YES

CONFIGURE_ARGS+=	--enable-graphics

.include "../../www/links/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
