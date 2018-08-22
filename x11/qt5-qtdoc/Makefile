# $NetBSD: Makefile,v 1.40 2018/08/22 09:48:03 wiz Exp $

DISTNAME=	qtdoc-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
