# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:44 jmmv Exp $
#

DISTNAME=	wmtime-1.0b2
WRKSRC=		${WRKDIR}/wmtime.app/wmtime
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.netbsd.org/~ad/distfiles/

MAINTAINER=	ad@netbsd.org
COMMENT=	Time/Date applet for WindowMaker

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
