# $NetBSD: Makefile,v 1.50 2005/10/10 17:39:19 reed Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
PKGREVISION=		1
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL

.include "../../x11/tk/Makefile.version"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:C/-src//}/unix

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
MAKE_ENV+=		TOUCH=${TOUCH:Q}
PTHREAD_OPTS+=		require

TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

post-build:
	${SED} 								\
		-e "s|${WRKSRC}|${PREFIX}/lib|"				\
		-e "s|${WRKDIR}/${DISTNAME:C/-src//}|${PREFIX}/include/tk|"	\
		${WRKSRC}/tkConfig.sh > ${WRKSRC}/tkConfig.sh.tmp &&	\
		${MV} ${WRKSRC}/tkConfig.sh.tmp ${WRKSRC}/tkConfig.sh

post-install:
	${RM} -f ${PREFIX}/bin/wish
	cd ${PREFIX}/bin && ${LN} -s wish8.4 wish
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk/generic
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../generic/default.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/ks_names.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tk.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tk3d.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkButton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkCanvas.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkColor.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkFileFilter.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkFont.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkInitScript.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkInt.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntXlibDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkMenu.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkMenubutton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkPort.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkScale.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkScrollbar.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkSelect.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkText.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkUndo.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixDefault.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixInt.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixPort.h ${PREFIX}/include/tk/unix

.include "../../mk/bsd.pkg.mk"
