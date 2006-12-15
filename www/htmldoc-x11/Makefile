# $NetBSD: Makefile,v 1.11 2006/12/15 20:33:03 joerg Exp $
#

.include "../../www/htmldoc/Makefile.common"

PKGNAME=	htmldoc-x11-${HTMLDOC_VERSION}
PKGREVISION=	5
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript (GUI available)

CONFLICTS=		htmldoc-[0-9]*

CONFIGURE_ARGS+=	--with-gui --with-x

.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
