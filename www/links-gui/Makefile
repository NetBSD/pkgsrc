# $NetBSD: Makefile,v 1.7 2002/07/26 15:29:23 jschauma Exp $
#

PKGNAME=	links-gui-2.1.0.2
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-[0-9]*

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../www/links/Makefile.common"
