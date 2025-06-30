# $NetBSD: Makefile,v 1.102 2025/06/30 15:05:10 adam Exp $

DISTNAME=	qttranslations-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
COMMENT=	Qt5 translations

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
