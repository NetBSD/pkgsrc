# $NetBSD: Makefile,v 1.2 2014/01/01 11:52:43 wiz Exp $

PKGNAME=	qt5-qttranslations-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 translations

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qttranslations
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
