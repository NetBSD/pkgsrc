# $NetBSD: Makefile,v 1.12 2008/01/18 05:09:50 tnn Exp $
#

.include "../../www/htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	6
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
