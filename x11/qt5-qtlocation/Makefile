# $NetBSD: Makefile,v 1.3 2014/02/03 16:17:12 ryoon Exp $

PKGNAME=	qt5-qtlocation-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for qtlocation

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtlocation
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

PC_FILES=		Qt5Positioning.pc

post-install:
.for i in ${PC_FILES}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		${LN} -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
