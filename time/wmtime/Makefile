# $NetBSD: Makefile,v 1.2 2001/02/17 17:32:12 wiz Exp $
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.netbsd.org/~ad/distfiles/

MAINTAINER=	ad@netbsd.org
COMMENT=	Time/Date applet for WindowMaker

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
