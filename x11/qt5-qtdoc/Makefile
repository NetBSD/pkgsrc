# $NetBSD: Makefile,v 1.63 2020/11/21 11:22:32 adam Exp $

DISTNAME=	qtdoc-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
