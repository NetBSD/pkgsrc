# $NetBSD: Makefile,v 1.26 2017/02/28 15:20:12 ryoon Exp $

DISTNAME=	qtdoc-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
PKGREVISION=	10
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
