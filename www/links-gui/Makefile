# $NetBSD: Makefile,v 1.19 2003/02/25 11:20:41 wiz Exp $
#

PKGNAME=	links-gui-2.1.0.8

COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-0.3*

USE_BUILDLINK2=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../www/links/Makefile.common"
.include "../../mk/bsd.pkg.mk"
