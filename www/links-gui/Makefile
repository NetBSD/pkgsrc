# $NetBSD: Makefile,v 1.9 2002/08/26 06:15:25 jlam Exp $
#

PKGNAME=	links-gui-2.1.0.2
COMMENT=	Lynx-like text and graphics WWW browser

CONFLICTS+=	links-[0-9]* elinks-[0-9]*

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../www/links/Makefile.common"

CONFIGURE_ARGS+=	--enable-graphics

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../www/links/Makefile.common"
.include "../../mk/bsd.pkg.mk"
