# $NetBSD: Makefile,v 1.55 2008/01/18 05:10:07 tnn Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
# XXX: hack - work round an ICE with GCC 3.3 on sparc
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
GCC_REQD+=		3.4
.endif

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=	qt3-tools-${QTVERSION}
PKGREVISION=	2
COMMENT=	QT GUI (WYSIWYG) builder and other tools

DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib

BUILD_QT3=		yes
UNLIMIT_RESOURCES=	datasize
BUILD_TARGET=		sub-tools

INSTALLATION_DIRS=	${QTPREFIX}/bin ${QTPREFIX}/lib			\
			${QTPREFIX}/plugins/designer ${QTPREFIX}/mkspecs

do-install:
	for bin in assistant designer linguist lrelease lupdate qm2ts	\
	    qmake qtconfig uic; do					\
		${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/bin/$$bin	\
		    ${DESTDIR}${QTPREFIX}/bin;				\
	done
	for lib in libeditor.la libqassistantclient.la libqui.la; do	\
		${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/lib/$$lib	\
		    ${DESTDIR}${QTPREFIX}/lib;				\
	done
	for plugin in libwizards.la libcppeditor.la libdlgplugin.la	\
	    librcplugin.la libkdevdlgplugin.la; do			\
		${LIBTOOL} ${INSTALL_PROGRAM}				\
		    ${WRKSRC}/plugins/designer/$$plugin			\
		    ${DESTDIR}${QTPREFIX}/plugins/designer;		\
	done
	cd ${WRKSRC}/mkspecs && ${PAX} -rw . ${DESTDIR}${QTPREFIX}/mkspecs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
