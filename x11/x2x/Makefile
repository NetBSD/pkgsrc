# $NetBSD: Makefile,v 1.14 2008/04/19 06:04:56 obache Exp $

DISTNAME=	x2x-1.27
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://gatekeeper.hpl.hp.com/pub/DEC/SRC/x2x/ \
		http://gatekeeper.hpl.hp.com/archive/pub/DEC/SRC/x2x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x2x.dottedmag.net/
COMMENT=	One keyboard and mouse to control multiple X displays

USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
