# $NetBSD: Makefile,v 1.18 2012/10/29 05:06:57 asau Exp $

DISTNAME=	x2x-1.27
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://apotheca.hpl.hp.com/ftp/pub/Compaq/SRC/x2x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x2x.dottedmag.net/
COMMENT=	One keyboard and mouse to control multiple X displays

USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
