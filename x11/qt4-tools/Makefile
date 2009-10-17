# $NetBSD: Makefile,v 1.27 2009/10/17 23:32:52 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tools-${QTVERSION}
PKGREVISION=	1
COMMENT=	QT GUI (WYSIWYG) builder and other tools

DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-DQT_NO_DBUS

BUILD_TARGET=		sub-tools sub-tools-qdoc3

BUILD_QT4=		yes
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	${QTPREFIX}/bin ${QTPREFIX}/lib lib/pkgconfig \
	${QTPREFIX}/plugins/designer ${QTPREFIX}/phrasebooks \
	${QTPREFIX}/mkspecs ${QTPREFIX}/tools/qdoc3
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

post-configure:
	ln -s ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	ln -s ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	ln -s ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

do-install:
.for prog in assistant_adp lrelease lupdate pixeltool qmake qt3to4
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${DESTDIR}${QTPREFIX}/bin/
.endfor
.for prog in assistant designer linguist qtconfig qhelpconverter \
		qhelpgenerator qcollectiongenerator
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qdoc3/qdoc3 \
		${DESTDIR}${QTPREFIX}/tools/qdoc3/
	cd ${WRKSRC}/tools/assistant/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_flat_headers install_targ_headers install_class_headers
	cd ${WRKSRC}/tools/assistant/compat/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_assistant_headers
	cd ${WRKSRC}/tools/designer/src/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_designer_headers
	cd ${WRKSRC}/tools/designer/src/uitools && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_quitools_headers
.for lib in QtAssistantClient QtCLucene QtDesigner QtDesignerComponents QtHelp QtUiTools
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${lib}.la \
		${DESTDIR}${QTPREFIX}/lib/
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
