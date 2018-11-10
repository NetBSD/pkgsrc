# $NetBSD: Makefile,v 1.34 2018/11/10 19:33:47 bsiegert Exp $

DISTNAME=	qtdeclarative-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtdeclarative-${QTVERSION}
COMMENT=	Qt5 module for declarative framework
PKGREVISION=	1

BUILD_TARGET=		sub-tools
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Qml.pc Qt5Quick.pc Qt5QuickTest.pc Qt5QuickWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
