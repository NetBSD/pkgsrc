# $NetBSD: Makefile,v 1.6 2014/04/23 07:05:32 adam Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtquickcontrols-${QTVERSION}
COMMENT=	Qt5 module for QuickControls

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qtquickcontrols
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
