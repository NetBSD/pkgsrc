# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:08 rillig Exp $
#

DISTNAME=	TclDOM-1.6
PKGNAME=	tcl-dom-1.6
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/in-tcldom/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/in-tcldom/
COMMENT=	DOM implementation for use with TclXML or TclExpat

DEPENDS+=	tcl-xml-[0-9]*:../../textproc/tcl-xml

# old name for this package...
CONFLICTS+=	TclDom-[0-9]*

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dom.tcl ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dommap.tcl ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/tcl/TclDOM

.include "../../mk/bsd.pkg.mk"
