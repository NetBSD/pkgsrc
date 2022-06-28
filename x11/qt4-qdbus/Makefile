# $NetBSD: Makefile,v 1.49 2022/06/28 11:37:58 wiz Exp $

PKGREVISION= 8
.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-qdbus-${QTVERSION}
COMMENT=	QT DBus support

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-qdbus

USE_TOOLS+=		pkg-config
TOOLS_BROKEN+=		perl

BUILD_QT4=		yes

post-configure:
	ln -s ${QTPREFIX}/bin/moc ${WRKSRC}/bin/moc
	ln -s ${QTPREFIX}/bin/uic ${WRKSRC}/bin/uic
	ln -s ${QTPREFIX}/bin/rcc ${WRKSRC}/bin/rcc

do-build:
	cd ${WRKSRC}/src/dbus && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/tools/qdbus && env ${MAKE_ENV} ${GMAKE}

INSTALLATION_DIRS=	${QTPREFIX}/bin ${QTPREFIX}/lib lib/pkgconfig

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libQtDBus.la \
		${DESTDIR}${QTPREFIX}/lib/
	${SED} -e "s:${WRKSRC}:${QTPREFIX}:g" \
		${WRKSRC}/lib/pkgconfig/QtDBus.pc > ${WRKDIR}/QtDBus.pc
	${INSTALL_DATA} ${WRKDIR}/QtDBus.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/
	cd ${WRKSRC}/src/dbus && env ${MAKE_ENV} INSTALL_ROOT=${DESTDIR} \
                ${MAKE_PROGRAM} install_flat_headers install_targ_headers install_class_headers
.for f in qdbus qdbuscpp2xml qdbusviewer qdbusxml2cpp
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} \
		${DESTDIR}${QTPREFIX}/bin
.endfor

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
