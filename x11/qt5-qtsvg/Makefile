# $NetBSD: Makefile,v 1.3 2014/02/03 16:17:13 ryoon Exp $

.include "../../x11/qt5-qtbase/Makefile.common"

PKGNAME=	qt5-qtsvg-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for SVG

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtsvg
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
.for i in Qt5Svg.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
