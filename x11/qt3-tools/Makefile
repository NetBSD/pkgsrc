# $NetBSD: Makefile,v 1.27 2004/10/03 00:18:38 tv Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-tools-${QTVERSION}
PKGREVISION=		1
COMMENT=		QT GUI (WYSIWYG) builder and other tools

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib

USE_BUILDLINK3=		yes
BUILD_QT3=		yes
UNLIMIT_RESOURCES=	datasize
ALL_TARGET=		sub-tools

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/lib/libqui.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/lib/libeditor.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqassistantclient.la \
		${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/designer ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libwizards.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libcppeditor.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libdlgplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/librcplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libkdevdlgplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/assistant ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/linguist ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/lupdate ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/lrelease ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qm2ts ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qtconfig ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qmake ${QTPREFIX}/bin/qmake
	${INSTALL_DATA_DIR} ${QTPREFIX}/mkspecs
	${CP} -R ${WRKSRC}/mkspecs ${QTPREFIX}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
