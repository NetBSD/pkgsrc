# $NetBSD: Makefile,v 1.1.1.1 2002/01/07 08:09:16 skrll Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-tools-${QTVERSION}
COMMENT=		QT GUI (WYSIWYG) builder and other tools

CONFIGURE_ARGS+=	-I${BUILDLINK_QTDIR}/include \
			-L${BUILDLINK_QTDIR}/lib

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt3-libs=	qt3-libs-${QTVERSION}

ALL_TARGET=		sub-tools

do-install:
	${MKDIR} ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqjpeg.la ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/imageformats/libqmng.la ${QTPREFIX}/plugins/imageformats
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqui.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/designer ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/lib/libeditor.la ${QTPREFIX}/lib
	${MKDIR} ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libwizards.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libcppeditor.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/libdlgplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/plugins/designer/librcplugin.la ${QTPREFIX}/plugins/designer
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/assistant ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/linguist ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qm2ts ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/qtconfig ${QTPREFIX}/bin

.include "../../x11/qt3-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
