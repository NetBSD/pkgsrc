# $NetBSD: Makefile,v 1.7 2014/04/23 07:05:32 adam Exp $

PKGNAME=	qt5-qtsensors-${QTVERSION}
COMMENT=	Qt5 module for Sensors

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qtsensors
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
.for i in Qt5Sensors.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
