# $NetBSD: Makefile,v 1.5 2003/06/02 01:15:37 jschauma Exp $

DISTNAME=	x2x-1.27
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.digital.com/pub/Digital/SRC/x2x/ \
		ftp://ftp.digital.de/Digital/SRC/x2x/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	One keyboard and mouse to control multiple X displays

USE_X11BASE=	yes
USE_IMAKE=	yes

post-configure:
	(cd ${WRKSRC}; ${LN} -s x2x.1 x2x.man)

.include "../../mk/bsd.pkg.mk"
