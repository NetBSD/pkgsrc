# $NetBSD: Makefile,v 1.30 2017/09/18 09:53:40 maya Exp $

DISTNAME=	qtdoc-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdoc-${QTVERSION}
PKGREVISION=	14
COMMENT=	Qt5 documentations

MAKE_ENV+=		QTDIR=${QTDIR}

BUILD_TARGET=		docs
INSTALL_TARGET=		install_docs

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
