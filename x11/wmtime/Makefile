# $NetBSD: Makefile,v 1.3 2000/05/28 15:00:34 dmcmahill Exp $

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.mezaway.org/pub/DockApps/

MAINTAINER=	ad@netbsd.org

DEPENDS=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	1
WRKSRC=		${WRKDIR}/wmtime.app/wmtime

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile
	${TOUCH} ${WRKSRC}/wmtime.man

do-configure:
	cd ${WRKSRC} && imake -DUseInstalled -DUseGccMakeDepend -I${X11BASE}/lib/X11/config && \
	${MAKE} Makefiles && \
	${MAKE} includes && \
	${MAKE} depend

.include "../../mk/bsd.pkg.mk"
