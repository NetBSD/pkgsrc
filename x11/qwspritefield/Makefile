# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:38 tv Exp $

DISTNAME=	QwSpriteField1.6
PKGNAME=	qwspritefield-1.6
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.troll.no/contrib/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Efficiently redrawn sprites in the Qt GUI Toolkit

DEPENDS+=	qt1-1.44:../../x11/qt1

CONFLICTS=	kdesupport-1.0

WRKSRC=		${WRKDIR}/QwSpriteField
USE_X11BASE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

QW_INCLUDES=	Pix.h QwCluster.h QwPublicList.h QwSpriteField.h

EVAL_PREFIX+=	QT1DIR=qt1
PATH:=		${QT1DIR}/qt1/bin:${PATH}

MAKE_ENV+=	CXX="${CXX}" "QTDIR=${QT1DIR}/qt1"

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libQwSpriteField.la \
	  ${PREFIX}/lib
	@QT1DIR=${QT1DIR};		\
	for FILE in ${QW_INCLUDES}; do					\
		${INSTALL_DATA} ${WRKSRC}/$$FILE $$QT1DIR/qt1/include;	\
	done

.include "../../mk/bsd.pkg.mk"
