# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:55 tron Exp $

PKGNAME=	qt5-qtdeclarative-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for declarative framework

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtdeclarative

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

QTPROG_BIN=		qmlbundle qmlmin qmlplugindump qmlprofiler \
			qmlscene qmltestrunner

post-install:
.for prog in ${QTPROG_BIN}
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/${BUILD_DIRS}/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin/${prog}
.endfor
.for i in Qt5Qml.pc Qt5QmlDevTools.pc Qt5Quick.pc Qt5QuickParticles.pc \
		Qt5QuickTest.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
