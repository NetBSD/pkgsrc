# $NetBSD: Makefile,v 1.108 2026/09/02 19:05:27 wiz Exp $

DISTNAME=	qtdoc-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
PKGREVISION=	2

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
