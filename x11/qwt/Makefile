# $NetBSD: Makefile,v 1.2 2000/03/23 23:15:25 dmcmahill Exp $

DISTNAME=	qwtlib-0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/contrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.troll.no/qtprogs.html

DEPENDS+=	qt1-1.44:../../x11/qt1

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
