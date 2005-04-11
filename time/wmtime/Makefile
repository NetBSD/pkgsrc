# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:45 tv Exp $
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.NetBSD.org/~ad/distfiles/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Time/Date applet for WindowMaker

WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USE_IMAKE=	YES

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
