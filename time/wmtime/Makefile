# $NetBSD: Makefile,v 1.7 2004/01/20 12:27:16 agc Exp $
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.NetBSD.org/~ad/distfiles/

MAINTAINER=	ad@NetBSD.org
COMMENT=	Time/Date applet for WindowMaker

WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USE_BUILDLINK2=	YES
USE_IMAKE=	YES

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
