# $NetBSD: Makefile,v 1.1.1.1 1999/11/11 16:34:33 ad Exp $

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.mezaway.org/pub/DockApps/
MAINTAINER=	ad@netbsd.org
DEPENDS=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	yes
USE_X11=	yes
NO_INSTALL_MANPAGES=	1
WRKSRC=		${WRKDIR}/wmtime.app/wmtime

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile
	touch ${WRKSRC}/wmtime.man

.include <../../mk/bsd.pkg.mk>
