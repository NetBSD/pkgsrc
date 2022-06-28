# $NetBSD: Makefile,v 1.76 2022/06/28 11:37:58 wiz Exp $

PKGREVISION= 9
.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-tools-${QTVERSION}
COMMENT=	QT GUI (WYSIWYG) builder and other tools

DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

TOOLS_BROKEN+=		perl

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-DQT_NO_DBUS

# XXX this is to test what really gets installed when 'do-install' is disabled
INSTALL_DIRS+=		tools

BUILD_TARGET=		sub-tools-bootstrap sub-tools

BUILD_QT4=		yes
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	lib/pkgconfig
INSTALLATION_DIRS+=	${QTPREFIX}/bin
INSTALLATION_DIRS+=	${QTPREFIX}/lib
INSTALLATION_DIRS+=	${QTPREFIX}/phrasebooks
INSTALLATION_DIRS+=	${QTPREFIX}/plugins/designer
INSTALLATION_DIRS+=	${QTPREFIX}/mkspecs
INSTALLATION_DIRS+=	${QTPREFIX}/tools/qdoc3
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

post-configure:
	ln -sf ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	ln -sf ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	ln -sf ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

QTPROG_BIN=	lconvert lrelease lupdate pixeltool qdoc3 qmake qt3to4
QTPROG_BIN+=	qttracereplay xmlpatterns xmlpatternsvalidator
QTPROG_LT=	qcollectiongenerator qhelpconverter qhelpgenerator
.if ${OPSYS} == "Darwin"
QTPROG_BIN+=	QMLViewer macdeployqt
QTPROG_LT+=	Assistant Designer Linguist
.else
QTPROG_BIN+=	qmlviewer qtconfig
QTPROG_LT+=	assistant designer linguist
.endif

do-install:
.for f in ${QTPROG_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${DESTDIR}${QTPREFIX}/bin/${f:tl}
.endfor
.for f in ${QTPROG_LT}
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} \
		${DESTDIR}${QTPREFIX}/bin/${f:tl}
.endfor
	cd ${WRKSRC}/tools/assistant/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_flat_headers install_targ_headers install_class_headers
	cd ${WRKSRC}/tools/designer/src/lib && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_designer_headers
	cd ${WRKSRC}/tools/designer/src/uitools && env ${MAKE_ENV} ${INSTALL_ENV} \
		${MAKE_PROGRAM} install_quitools_headers
.for f in QtCLucene QtDesigner QtDesignerComponents QtHelp QtUiTools
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/lib${f}.la \
		${DESTDIR}${QTPREFIX}/lib/
	sed -e "s:${WRKSRC}:${QTPREFIX}:g" \
		${WRKSRC}/lib/pkgconfig/${f}.pc > ${WRKDIR}/${f}.pc
	${INSTALL_DATA} ${WRKDIR}/${f}.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/
.endfor
.for f in qdeclarativeview qt3supportwidgets qwebview
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/plugins/designer/lib${f}.la \
		${DESTDIR}${QTPREFIX}/plugins/designer/
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/linguist/phrasebooks/*.qph \
		${DESTDIR}${QTPREFIX}/phrasebooks/
	cp -LR ${WRKSRC}/mkspecs ${DESTDIR}${QTPREFIX}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
