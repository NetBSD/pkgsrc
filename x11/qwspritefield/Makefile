# $NetBSD: Makefile,v 1.7 2000/07/11 14:53:48 agc Exp $

DISTNAME=	QwSpriteField1.6
PKGNAME=	qwspritefield-1.6
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.troll.no/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	qt1-1.44:../../x11/qt1

CONFLICTS=	kdesupport-1.0

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes
WRKSRC=		${WRKDIR}/QwSpriteField

QW_INCLUDES=	Pix.h QwCluster.h QwPublicList.h QwSpriteField.h

PATH=		`${MAKE} show-qt1-prefix`/qt1/bin:$$PATH

MAKE_ENV+=	"QTDIR=`${MAKE} show-qt1-prefix`/qt1"

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libQwSpriteField.la \
	  ${PREFIX}/lib
	@qt1dir=`${MAKE} show-qt1-prefix`;		\
	for file in ${QW_INCLUDES}; do					\
		${INSTALL_DATA} ${WRKSRC}/${FILE} $$qt1dir/qt1/include;	\
	done

.include "../../mk/bsd.pkg.mk"
