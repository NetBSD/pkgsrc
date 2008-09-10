# $NetBSD: Makefile,v 1.61.10.1 2008/09/10 10:47:31 tron Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL

.include "../../x11/tk/Makefile.version"

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
MAKE_ENV+=		TOUCH=${TOUCH:Q}
PTHREAD_OPTS+=		require

TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

INSTALLATION_DIRS+=	include/tk
INSTALLATION_DIRS+=	include/tk/generic
INSTALLATION_DIRS+=	include/tk/unix

DESTDIRPREFIX=		${DESTDIR}${PREFIX}

post-install:
	rm -f ${DESTDIRPREFIX:Q}/bin/wish
	ln -s wish8.4 ${DESTDIRPREFIX:Q}/bin/wish
	${INSTALL_DATA} ${WRKSRC}/generic/default.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/ks_names.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk3d.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkButton.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkCanvas.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkColor.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFileFilter.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFont.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInitScript.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInt.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntPlatDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntXlibDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenu.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenubutton.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPlatDecls.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPort.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScale.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScrollbar.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkSelect.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkText.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkUndo.h ${DESTDIRPREFIX:Q}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixDefault.h ${DESTDIRPREFIX:Q}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixInt.h ${DESTDIRPREFIX:Q}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixPort.h ${DESTDIRPREFIX:Q}/include/tk/unix

.include "../../mk/bsd.pkg.mk"
