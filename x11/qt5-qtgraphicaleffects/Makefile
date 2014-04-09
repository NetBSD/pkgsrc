# $NetBSD: Makefile,v 1.5 2014/04/09 07:27:19 obache Exp $

PKGNAME=	qt5-qtgraphicaleffects-${QTVERSION}
PKGREVISION=	4
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
