# $NetBSD: Makefile,v 1.31 2014/02/06 17:27:47 drochner Exp $
#

DISTNAME=	QScintilla-gpl-2.8
PKGNAME=	qt4-${DISTNAME:tl:S/-gpl-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.riverbankcomputing.co.uk/software/qscintilla/intro
COMMENT=	Scintilla C++ editor class for Qt
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/Qt4Qt5

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++

MAKE_ENV+=	QTPREFIX=${QTDIR}

INSTALLATION_DIRS=	${QTDIR}/lib ${QTDIR}/include

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	(mkdir ${DESTDIR}${QTDIR}/include/Qsci)
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libqscintilla2.la ${DESTDIR}${QTDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/Qsci/qsci*.h ${DESTDIR}${QTDIR}/include/Qsci

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
