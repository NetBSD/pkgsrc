# $NetBSD: Makefile,v 1.1.1.1 2000/01/07 05:43:21 sakamoto Exp $
#

DISTNAME=	wmfstatus-0.3
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.finik.net/software.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	yes

CPPFLAGS=	-I${X11BASE}/include
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../mk/bsd.pkg.mk"
