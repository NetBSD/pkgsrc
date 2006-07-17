# $NetBSD: Makefile,v 1.7 2006/07/17 15:30:16 minskim Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tools-${QTVERSION}
PKGREVISION=	1
COMMENT=	QT GUI (WYSIWYG) builder and other tools

DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_TARGET=		sub-tools

BUILD_QT4=		yes
UNLIMIT_RESOURCES=	datasize

post-configure:
	${LN} -s ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	${LN} -s ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	${LN} -s ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

do-install:
.for prog in assistant linguist lrelease lupdate qm2ts qmake qt3to4
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${QTPREFIX}/bin/
.endfor
.for prog in designer qtconfig
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} \
		${QTPREFIX}/bin
.endfor
	cd ${WRKSRC}/tools/assistant/lib && env ${MAKE_ENV} \
		${MAKE_PROGRAM} -f Makefile.Release install_assistant_headers
	cd ${WRKSRC}/tools/designer/src/lib && env ${MAKE_ENV} \
		${MAKE_PROGRAM} -f Makefile.Release install_designer_headers
	cd ${WRKSRC}/tools/qtestlib/src && env ${MAKE_ENV} \
		${MAKE_PROGRAM} -f Makefile install_qtestlib_headers
	${INSTALL_LIB} ${WRKSRC}/lib/libQtAssistantClient.a ${QTPREFIX}/lib/
.for lib in QtDesigner QtDesignerComponents QtTest
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${QTPREFIX}/lib/
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/QtTest.pc ${PREFIX}/lib/pkgconfig/
	${INSTALL_LIB_DIR} ${QTPREFIX}/plugins/designer
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/designer/libqt3supportwidgets.la \
		${QTPREFIX}/plugins/designer/
	${INSTALL_DATA_DIR} ${QTPREFIX}/phrasebooks
	${INSTALL_DATA} ${WRKSRC}/tools/linguist/phrasebooks/*.qph \
		${QTPREFIX}/phrasebooks/
	${INSTALL_DATA_DIR} ${QTPREFIX}/mkspecs
	${CP} -R ${WRKSRC}/mkspecs ${QTPREFIX}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
