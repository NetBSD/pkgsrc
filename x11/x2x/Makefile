# $NetBSD: Makefile,v 1.2 2000/02/05 16:08:45 wiz Exp $

DISTNAME=	x2x-1.27
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/Digital/SRC/x2x/ \
		ftp://ftp.digital.de/Digital/SRC/x2x/

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

post-install:
	(cd ${WRKSRC}; ${INSTALL_MAN} x2x.1 ${PREFIX}/man/man1)

.include "../../mk/bsd.pkg.mk"
