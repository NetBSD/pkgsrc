# $NetBSD: Makefile,v 1.1.1.1 2000/08/29 16:16:06 jwise Exp $

DISTNAME=	tk8.3.2
PKGNAME=	tk-8.3.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_3/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.tcltk.com/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib

USE_X11=	yes

USE_LIBTOOL=	yes

post-install:
	cd ${PREFIX}/bin && ${LN} -s wish8.3 wish
	${MKDIR} ${PREFIX}/include/tk
	${MKDIR} ${PREFIX}/include/tk/generic
	${MKDIR} ${PREFIX}/include/tk/unix
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
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixDefault.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixInt.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixPort.h ${PREFIX}/include/tk/unix

test:
	cd ${WRKSRC}; ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
