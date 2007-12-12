# $NetBSD: Makefile,v 1.2 2007/12/12 11:56:10 markd Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-qdbus-${QTVERSION}
COMMENT=	QT DBus support

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-qdbus

BUILD_QT4=		yes

post-configure:
	ln -s ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	ln -s ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	ln -s ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

do-build:
	cd ${WRKSRC}/tools/qdbus && env ${MAKE_ENV} ${GMAKE}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libQtDBus.la \
		${QTPREFIX}/lib/
	${SED} -e "s:${WRKSRC}:${QTPREFIX}:g" \
		${WRKSRC}/lib/pkgconfig/QtDBus.pc > ${WRKDIR}/QtDBus.pc
	${INSTALL_DATA} ${WRKDIR}/QtDBus.pc ${PREFIX}/lib/pkgconfig/
	cd ${WRKSRC}/tools/qdbus/src && env ${MAKE_ENV} \
                ${MAKE_PROGRAM} install_qtdbus_headers
.for prog in qdbus qdbuscpp2xml qdbusviewer qdbusxml2cpp
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} \
		${QTPREFIX}/bin
.endfor

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
