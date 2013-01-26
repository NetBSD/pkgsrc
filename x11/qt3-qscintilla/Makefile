# $NetBSD: Makefile,v 1.28 2013/01/26 21:36:57 adam Exp $
#

DISTNAME=		qscintilla-1.65-gpl-1.6
PKGNAME=		qt3-qscintilla-1.6
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/QScintilla/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/qscintilla/
COMMENT=		Scintilla C++ editor class for Qt

WRKSRC=			${WRKDIR}/${DISTNAME}/qt

# needs qmake
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c++

MAKE_ENV+=	QTPREFIX=${QTDIR:Q}

INSTALLATION_DIRS=	${QTDIR}/lib ${QTDIR}/include

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
	    ${WRKSRC}/libqscintilla.la ${DESTDIR}${QTDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/qextscintilla*.h ${DESTDIR}${QTDIR}/include

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
