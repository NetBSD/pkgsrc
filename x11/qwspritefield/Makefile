# $NetBSD: Makefile,v 1.10 2000/08/06 16:37:02 tron Exp $

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

EVAL_PREFIX+=	QT1DIR=qt1
PATH:=		${QT1DIR}/qt1/bin:${PATH}

MAKE_ENV+=	"QTDIR=${QT1DIR}/qt1"

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libQwSpriteField.la \
	  ${PREFIX}/lib
	@QT1DIR=${QT1DIR};		\
	for FILE in ${QW_INCLUDES}; do					\
		${INSTALL_DATA} ${WRKSRC}/$$FILE $$QT1DIR/qt1/include;	\
	done

.include "../../mk/bsd.pkg.mk"
