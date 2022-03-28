# $NetBSD: Makefile,v 1.71 2022/03/28 10:59:50 tnn Exp $

DISTNAME=	qttranslations-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
PKGREVISION=	8
COMMENT=	Qt5 translations

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
