# $NetBSD: Makefile,v 1.19 2003/11/12 03:39:44 jschauma Exp $
#

.include "${.CURDIR}/Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
PKGREVISION=	1
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
