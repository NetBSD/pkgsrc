# $NetBSD: Makefile,v 1.8 2001/04/30 11:03:30 skrll Exp $

DISTNAME=	qwt-0.3.0
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qwt/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/qwt
COMMENT=	Qt widget library for technical purposes

DEPENDS+=	qt2-libs-2.3.0:../../x11/qt2-libs

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

EVAL_PREFIX+=	QT2DIR=qt2-libs
MAKE_ENV+=	CXX="${CXX}" \
		QTDIR="${QT2DIR}/qt2"

CONFLICTS=	qwtlib-*

post-patch:
	${LN} -s ${WRKSRC}/makefiles/netbsd-g++ ${WRKSRC}/Makefile

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libqwt.la \
	  ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwt
	${INSTALL_DATA} ${WRKSRC}/doc/man/man3/* ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
