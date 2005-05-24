# $NetBSD: Makefile,v 1.21 2005/05/24 14:24:45 rillig Exp $
#

.include "Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
PKGREVISION=	2
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
