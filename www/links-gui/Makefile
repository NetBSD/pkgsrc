# $NetBSD: Makefile,v 1.5 2002/07/26 15:12:58 jschauma Exp $
#

PKGNAME=	links-gui-2.1.0.2
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-[0-9]*

BUILD_DEPENDS+=		x11-links>=0.7:../../pkgtools/x11-links

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../www/links/Makefile.common"
.include "../../mk/x11.buildlink.mk"
