# $NetBSD: Makefile,v 1.5 2000/08/23 23:14:36 tron Exp $

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11
MASTER_SITES=	http://www.netbsd.org/~ad/distfiles/

MAINTAINER=	ad@netbsd.org

USE_IMAKE=	YES
USE_XPM=	YES

NO_INSTALL_MANPAGES=	YES
WRKSRC=			${WRKDIR}/wmtime.app/wmtime

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile
	${TOUCH} ${WRKSRC}/wmtime.man

do-configure:
	cd ${WRKSRC} && imake -DUseInstalled -DUseGccMakeDepend -I${X11BASE}/lib/X11/config && \
	${MAKE} Makefiles && \
	${MAKE} includes && \
	${MAKE} depend

.include "../../mk/bsd.pkg.mk"
