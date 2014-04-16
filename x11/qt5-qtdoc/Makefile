# $NetBSD: Makefile,v 1.7 2014/04/16 11:22:04 wiz Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtdoc-${QTVERSION}
PKGREVISION=	6
COMMENT=	Qt5 documentations

USE_LIBTOOL=		yes

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_DIRS+=		qtdoc

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
