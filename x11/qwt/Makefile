# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:38 tv Exp $

DISTNAME=	qwt-0.3.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qwt/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/qwt
COMMENT=	Qt widget library for technical purposes

USE_BUILDLINK3=	yes
USE_X11BASE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"

CONFLICTS=	qwtlib-[0-9]*

post-patch:
	${LN} -s ${WRKSRC}/makefiles/netbsd-g++ ${WRKSRC}/Makefile

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libqwt.la \
	  ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/doc/man/man3/* ${PREFIX}/man/man3

.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
