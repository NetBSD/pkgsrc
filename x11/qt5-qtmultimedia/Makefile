# $NetBSD: Makefile,v 1.9 2014/04/23 07:05:32 adam Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtmultimedia-${QTVERSION}
COMMENT=	Qt5 module for multimedia

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qtmultimedia
BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
.for i in Qt5Multimedia.pc Qt5MultimediaQuick_p.pc Qt5MultimediaWidgets.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.if ${OPSYS} != "Darwin"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
