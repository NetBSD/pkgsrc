# $NetBSD: Makefile,v 1.41 2016/03/05 11:28:00 jperkin Exp $

PKGREVISION= 1
.include "../../x11/qt4-qscintilla/Makefile.common"

PKGNAME=	qt4-${DISTNAME:tl:S/-gpl-/-/}
COMMENT=	Scintilla C++ editor class for Qt

WRKSRC=		${WRKDIR}/${DISTNAME}/Qt4Qt5

USE_TOOLS+=	gmake
MAKE_ENV+=	QTPREFIX=${QTDIR}
INSTALLATION_DIRS=	${QTDIR}/lib ${QTDIR}/include

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	(mkdir ${DESTDIR}${QTDIR}/include/Qsci)
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libqscintilla2.la ${DESTDIR}${QTDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/Qsci/qsci*.h ${DESTDIR}${QTDIR}/include/Qsci

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
