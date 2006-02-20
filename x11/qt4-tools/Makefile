# $NetBSD: Makefile,v 1.1.1.1 2006/02/20 12:09:01 adam Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tools-${QTVERSION}
COMMENT=	QT GUI (WYSIWYG) builder and other tools

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_QT4=		yes
UNLIMIT_RESOURCES=	datasize
BUILD_TARGET=		sub-tools

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
.for inc in QtAssistant QtDesigner QtTest QtUiTools
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/${inc}
	${INSTALL_DATA} ${WRKSRC}/include/${inc}/*.h ${QTPREFIX}/include/${inc}/
.endfor
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
