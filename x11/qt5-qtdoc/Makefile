# $NetBSD: Makefile,v 1.75 2022/09/13 17:18:04 adam Exp $

DISTNAME=	qtdoc-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
