# $NetBSD: Makefile,v 1.3 2002/06/30 04:02:54 jlam Exp $
#

PKGNAME=	links-gui-2.0
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-[0-9]*

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../www/links/Makefile.common"
.include "../../mk/x11.buildlink.mk"
