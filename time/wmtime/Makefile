# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:11 joerg Exp $
#

DISTNAME=	wmtime-1.0b2
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	ftp://ftp.alpha.alt.ru/pub/UNIX/X11/WMaker/ \
		http://www.NetBSD.org/~ad/distfiles/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Time/Date applet for WindowMaker

WRKSRC=		${WRKDIR}/wmtime.app
USE_IMAKE=	YES
CONFIGURE_DIRS=	wmtime
BUILD_DIRS=	${CONFIGURE_DIRS}

post-extract:
	${CP} ${WRKSRC}/Imakefile ${WRKSRC}/wmtime/Imakefile

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
