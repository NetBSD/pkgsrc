# $NetBSD: Makefile,v 1.3 2001/02/17 17:06:57 wiz Exp $

DISTNAME=	x2x-1.27
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/Digital/SRC/x2x/ \
		ftp://ftp.digital.de/Digital/SRC/x2x/

MAINTAINER=	packages@netbsd.org
COMMENT=	One keyboard and mouse to control multiple X displays

USE_X11BASE=	yes
USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

post-install:
	(cd ${WRKSRC}; ${INSTALL_MAN} x2x.1 ${PREFIX}/man/man1)

.include "../../mk/bsd.pkg.mk"
