# $NetBSD: Makefile,v 1.18 2002/09/23 23:34:59 jlam Exp $
#

.include "${.CURDIR}/Makefile.common"

PKGNAME=	htmldoc-${HTMLDOC_VERSION}
COMMENT=	Converts HTML to indexed HTML, PDF and/or PostScript

CONFLICTS=		htmldoc-x11-[0-9]*

CONFIGURE_ARGS+=	--without-gui --without-x

.include "../../mk/bsd.pkg.mk"
