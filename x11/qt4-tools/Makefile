# $NetBSD: Makefile,v 1.18 2008/02/04 20:41:40 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tools-${QTVERSION}
PKGREVISION=	1
COMMENT=	QT GUI (WYSIWYG) builder and other tools

DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-DQT_NO_DBUS

BUILD_TARGET=		sub-tools

BUILD_QT4=		yes
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	${QTPREFIX}/bin ${QTPREFIX}/lib lib/pkgconfig \
	${QTPREFIX}/plugins/designer ${QTPREFIX}/phrasebooks \
	${QTPREFIX}/mkspecs
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

post-configure:
	ln -s ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	ln -s ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	ln -s ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

do-install:
.for prog in assistant lrelease lupdate qmake qt3to4
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${DESTDIR}${QTPREFIX}/bin/
.endfor
.for prog in designer linguist qtconfig
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin
.endfor
	cd ${WRKSRC}/tools/assistant/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_assistant_headers
	cd ${WRKSRC}/tools/designer/src/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_designer_headers
	cd ${WRKSRC}/tools/designer/src/uitools && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_quitools_headers
	cd ${WRKSRC}/tools/qtestlib/src && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_qtestlib_headers
.for lib in QtAssistantClient QtDesigner QtDesignerComponents QtTest
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${DESTDIR}${QTPREFIX}/lib/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libQtUiTools.la \
		${DESTDIR}${QTPREFIX}/lib/
.for lib in QtUiTools QtTest
	sed -e "s:${WRKSRC}:${QTPREFIX}:g" \
		${WRKSRC}/lib/pkgconfig/${lib}.pc > ${WRKDIR}/${lib}.pc
	${INSTALL_DATA} ${WRKDIR}/${lib}.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/
.endfor
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/designer/libqt3supportwidgets.la \
		${DESTDIR}${QTPREFIX}/plugins/designer/
	${INSTALL_DATA} ${WRKSRC}/tools/linguist/phrasebooks/*.qph \
		${DESTDIR}${QTPREFIX}/phrasebooks/
	cp -R ${WRKSRC}/mkspecs ${DESTDIR}${QTPREFIX}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
