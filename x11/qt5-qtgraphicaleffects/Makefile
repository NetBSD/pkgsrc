# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:55 tron Exp $

PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for Graphics effects

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtgraphicaleffects
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
