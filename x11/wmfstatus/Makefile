# $NetBSD: Makefile,v 1.23 2017/09/06 10:40:35 wiz Exp $

DISTNAME=	wmfstatus-0.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.finik.net/software.html
COMMENT=	General purpose 8x5 LCD screen for WindowMaker

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/wmfstatus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
	    ${WRKDIR}/${DISTNAME}/HINTS ${DESTDIR}${PREFIX}/share/doc/wmfstatus

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
