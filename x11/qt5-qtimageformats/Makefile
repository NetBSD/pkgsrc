# $NetBSD: Makefile,v 1.44 2020/04/12 08:28:14 adam Exp $

DISTNAME=	qtimageformats-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtimageformats-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for Image formats

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
