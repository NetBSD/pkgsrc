# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:21 wiz Exp $
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.netbsd.org/~ad/distfiles/

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
