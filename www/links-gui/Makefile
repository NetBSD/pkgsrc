# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 19:04:10 jlam Exp $
#

PKGNAME=	links-gui-2.0
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]*

USE_BUILDLINK2=	YES

.include "../../www/links/Makefile.common"

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
