# $NetBSD: Makefile,v 1.92 2024/05/25 14:21:22 adam Exp $

DISTNAME=	qttranslations-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
COMMENT=	Qt5 translations

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
