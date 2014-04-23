# $NetBSD: Makefile,v 1.6 2014/04/23 07:05:32 adam Exp $

PKGNAME=	qt5-qtxmlpatterns-${QTVERSION}
COMMENT=	Qt5 module for XML Patterns

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qtxmlpatterns
BUILD_TARGET=		sub-tools

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

QTPROG_BIN=		xmlpatterns xmlpatternsvalidator

post-install:
.for prog in ${QTPROG_BIN}
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/${BUILD_DIRS}/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin/${prog}
.endfor
.for i in Qt5XmlPatterns.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
