# $NetBSD: Makefile,v 1.2.2.3 2002/06/24 06:09:12 jlam Exp $
#

PKGNAME=	links-gui-2.0
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]*

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../www/links/Makefile.common"

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
