# $NetBSD: Makefile,v 1.106 2026/05/25 06:18:16 adam Exp $

DISTNAME=	qttranslations-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
