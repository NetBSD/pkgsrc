# $NetBSD: Makefile,v 1.15 2016/03/02 23:04:00 ryoon Exp $

DISTNAME=	qtdeclarative-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtdeclarative-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for declarative framework

BUILD_TARGET=		sub-tools
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Qml.pc Qt5QmlDevTools.pc Qt5Quick.pc Qt5QuickParticles.pc \
		Qt5QuickTest.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
