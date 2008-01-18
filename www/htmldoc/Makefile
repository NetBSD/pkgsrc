# $NetBSD: Makefile,v 1.23 2008/01/18 05:09:49 tnn Exp $
#

.include "Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
PKGREVISION=	4
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
