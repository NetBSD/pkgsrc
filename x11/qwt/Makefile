# $NetBSD: Makefile,v 1.16 2002/09/20 21:31:38 jlam Exp $

DISTNAME=	qwt-0.3.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qwt/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/qwt
COMMENT=	Qt widget library for technical purposes

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
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

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
