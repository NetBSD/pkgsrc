# $NetBSD: Makefile,v 1.2 2000/08/23 23:14:36 tron Exp $

DISTNAME=	wmfstatus-0.3
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.finik.net/software.html

USE_X11=	YES
USE_XPM=	YES

CPPFLAGS=	-I${X11BASE}/include
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../mk/bsd.pkg.mk"
