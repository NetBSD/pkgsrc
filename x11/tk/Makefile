# $NetBSD: Makefile,v 1.57 2006/11/02 17:42:03 adam Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL

.include "../../x11/tk/Makefile.version"

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
.include "../../mk/x11.buildlink3.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

INSTALLATION_DIRS+=	${PREFIX}/include/tk
INSTALLATION_DIRS+=	${PREFIX}/include/tk/generic
INSTALLATION_DIRS+=	${PREFIX}/include/tk/unix

post-install:
	rm -f ${PREFIX}/bin/wish
	ln -s wish8.4 ${PREFIX}/bin/wish
	${INSTALL_DATA} ${WRKSRC}/generic/default.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/ks_names.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk3d.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkButton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkCanvas.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkColor.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFileFilter.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFont.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInitScript.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInt.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntXlibDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenu.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenubutton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPort.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScale.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScrollbar.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkSelect.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkText.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkUndo.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixDefault.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixInt.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixPort.h ${PREFIX}/include/tk/unix

.include "../../mk/bsd.pkg.mk"
