# $NetBSD: Makefile,v 1.20 2004/03/26 02:27:57 wiz Exp $
#

.include "${.CURDIR}/Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
PKGREVISION=	2
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
