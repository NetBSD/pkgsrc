# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:55 tron Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtimageformats-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for Image formats

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtimageformats
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
