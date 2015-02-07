# $NetBSD: Makefile,v 1.1 2015/02/07 13:18:14 wiz Exp $

DISTNAME=	qtwebchannel-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtwebchannel-${QTVERSION}
COMMENT=	Qt5 WebChannel module

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_TOOLS+=		bison flex pkg-config sed

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.if ${USE_CWRAPPERS:Uno} == "yes"
BUILDLINK_TRANSFORM+=	R:${WRKSRC}/lib:${QTDIR}/lib
.else
BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/lib:${QTDIR}/lib
.endif

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
