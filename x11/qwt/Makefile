# $NetBSD: Makefile,v 1.1.1.1 1999/11/17 18:32:29 drochner Exp $

DISTNAME=	qwtlib-0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/contrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.troll.no/qtprogs.html

DEPENDS+=	qt-1.44:../../x11/qt

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/qwt
ALL_TARGET=	src

do-configure:
	${CP} ${FILESDIR}/Makefile.* ${WRKSRC}

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqwt.la \
	  ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/doc/man/* ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
