# $NetBSD: Makefile,v 1.1.1.1 1999/05/28 21:08:04 mjl Exp $

DISTNAME=	x2x-1.27
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/Digital/SRC/x2x/ \
		ftp://ftp.digital.de/Digital/SRC/x2x/

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ln -s x2x.1 x2x.man)

post-install:
	(cd ${WRKSRC}; ${INSTALL_MAN} x2x.1 ${PREFIX}/man/man1)

.include "../../mk/bsd.pkg.mk"
