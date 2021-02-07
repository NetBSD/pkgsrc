# $NetBSD: Makefile,v 1.66 2021/02/07 06:30:42 ryoon Exp $

DISTNAME=	qttranslations-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qttranslations-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 translations

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
