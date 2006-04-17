# $NetBSD: Makefile,v 1.22 2006/04/17 14:52:12 wiz Exp $
#

.include "Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
PKGREVISION=	3
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
