# $NetBSD: Makefile,v 1.13 2002/10/28 08:46:45 skrll Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-tools-${QTVERSION}
COMMENT=		QT GUI (WYSIWYG) builder and other tools

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib

MAKE_ENV+=              LIBQT="-lqt-mt"

USE_BUILDLINK2=		yes
BUILD_QT3=		yes
UNLIMIT_RESOURCES=	datasize
ALL_TARGET=		sub-tools

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqui.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/designer ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/lib/libeditor.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libwizards.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libcppeditor.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libdlgplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/librcplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/assistant ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/linguist ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qm2ts ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qtconfig ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qmake ${QTPREFIX}/bin/qmake
	${INSTALL_DATA_DIR} ${QTPREFIX}/mkspecs
	${CP} -R ${WRKSRC}/mkspecs ${QTPREFIX}

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
