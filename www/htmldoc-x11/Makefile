# $NetBSD: Makefile,v 1.8 2005/12/05 20:51:12 rillig Exp $
#

.include "../../www/htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	3
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
