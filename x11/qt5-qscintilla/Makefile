# $NetBSD: Makefile,v 1.9 2020/04/12 08:28:14 adam Exp $

PKGREVISION=	5
.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	qt5-${DISTNAME:tl:S/_gpl-/-/}
COMMENT=	Scintilla C++ editor class for Qt5

WRKSRC=		${WRKDIR}/${DISTNAME}/Qt4Qt5

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++

MAKE_ENV+=	QTPREFIX=${QTDIR}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../x11/qt5-qtmacextras/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
