# $NetBSD: Makefile,v 1.17 2006/03/11 04:56:48 reed Exp $
#

DISTNAME=		qscintilla-1.65-gpl-1.6
PKGNAME=		qt3-qscintilla-1.6
PKGREVISION=		2
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

MAKE_ENV+=	QTPREFIX=${QTDIR:Q}

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	${INSTALL_LIB_DIR} ${QTDIR}/lib
	(cd ${WRKSRC} && ${LIBTOOL} --mode=install \
		${INSTALL_DATA} libqscintilla.la ${QTDIR}/lib)
	${INSTALL_DATA_DIR} ${QTDIR}/include
	(cd ${WRKSRC} && ${CP} qextscintilla*.h ${QTDIR}/include)

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
