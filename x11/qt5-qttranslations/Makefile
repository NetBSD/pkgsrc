# $NetBSD: Makefile,v 1.109 2026/09/27 11:39:38 tnn Exp $

DISTNAME=	qttranslations-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
PKGREVISION=	3

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
