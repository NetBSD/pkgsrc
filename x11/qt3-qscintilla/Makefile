# $NetBSD: Makefile,v 1.7 2005/02/24 20:08:44 drochner Exp $
#

DISTNAME=		qscintilla-1.62-gpl-1.5
PKGNAME=		qt3-qscintilla-1.5
CATEGORIES=		x11
MASTER_SITES=		http://www.river-bank.demon.co.uk/download/QScintilla/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.riverbankcomputing.co.uk/qscintilla/
COMMENT=		C++ editor class

WRKSRC=			${WRKDIR}/${DISTNAME}/qt

# needs qmake
BUILD_DEPENDS+=		qt3-tools-3.*:../../x11/qt3-tools

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

MAKE_ENV+=	QTPREFIX=${QTDIR}

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	(cd ${WRKSRC} && ${LIBTOOL} --mode=install \
		${INSTALL_DATA} libqscintilla.la ${QTDIR}/lib)
	(cd ${WRKSRC} && ${CP} qextscintilla*.h ${QTDIR}/include)

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
