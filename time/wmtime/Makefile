# $NetBSD: Makefile,v 1.3 2002/10/21 13:08:54 wiz Exp $
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.netbsd.org/~ad/distfiles/

MAINTAINER=	ad@netbsd.org
COMMENT=	Time/Date applet for WindowMaker

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

NO_INSTALL_MANPAGES=	YES
WRKSRC=			${WRKDIR}/wmtime.app/wmtime

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile
	${TOUCH} ${WRKSRC}/wmtime.man

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
