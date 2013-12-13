# $NetBSD: Makefile,v 1.1 2013/12/13 14:38:35 ryoon Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtimageformats-${QTVERSION}
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
