# $NetBSD: Makefile,v 1.29 2004/04/29 09:28:21 wiz Exp $
#

PKGNAME=	links-gui-2.1.0.15

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*

USE_X11=	YES

CONFIGURE_ARGS+=	--enable-graphics

.include "../../www/links/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
