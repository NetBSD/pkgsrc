# $NetBSD: Makefile,v 1.9 2006/03/04 21:31:12 jlam Exp $

DISTNAME=	x2x-1.27
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/Digital/SRC/x2x/ \
		ftp://ftp.digital.de/Digital/SRC/x2x/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	One keyboard and mouse to control multiple X displays

USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

.include "../../mk/bsd.pkg.mk"
