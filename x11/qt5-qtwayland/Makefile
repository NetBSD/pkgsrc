# $NetBSD: Makefile,v 1.15 2020/11/05 09:09:27 ryoon Exp $

DISTNAME=	qtwayland-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtwayland-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for Wayland support

.include "../../devel/wayland/platform.mk"

.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Setting PREFIX in qmake files.
SUBST_FILES.conf+=	config.tests/wayland_scanner/wayland_scanner.pro
SUBST_FILES.conf+=	features/wayland-scanner-client-wayland-protocol-include.prf
SUBST_VARS.conf+=	PREFIX

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTPREFIX}/bin/qmake -o Makefile \
	    QMAKE_WAYLAND_SCANNER=${PREFIX}/bin/wayland-scanner

post-install:
.for i in Qt5Wayland.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
