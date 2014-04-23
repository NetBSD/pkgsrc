# $NetBSD: Makefile,v 1.9 2014/04/23 07:05:31 adam Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtdoc-${QTVERSION}
COMMENT=	Qt5 documentations

USE_LIBTOOL=		yes

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_DIRS=		qtdoc
BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
