# $NetBSD: Makefile,v 1.3.2.2 2002/08/22 11:13:50 jlam Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-tools-${QTVERSION}
PKGREVISION=		2
COMMENT=		QT GUI (WYSIWYG) builder and other tools

CONFIGURE_ARGS+=	-I${BUILDLINK_QTDIR}/include \
			-L${BUILDLINK_QTDIR}/lib

MAKE_ENV+=              LIBQT="-lqt-mt"

USE_BUILDLINK_ONLY=		yes
REPLACE_BUILDLINK_PATTERNS=	qmake.conf
# following QMAKE variables seem to be working empty; might need some
# adjusting eventually
REPLACE_BUILDLINK_SED=	-e 's/\(QMAKE_INCDIR[ 	]*=\) .*$$/\1/' \
			-e 's/\(QMAKE_LIBDIR[ 	]*=\) .*$$/\1/' \
			-e 's^\(QMAKE_INCDIR_OPENGL[ 	]*=\) .*$$^\1^' \
			-e 's^\(QMAKE_LIBDIR_OPENGL[ 	]*=\) .*$$^\1^'

PTHREAD_OPTS+=		require

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

.include "../../x11/qt3-libs/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
