# $NetBSD: Makefile,v 1.2 2001/02/17 17:37:44 wiz Exp $
#

DISTNAME=	TclDOM-1.6
PKGNAME=	tcl-dom-1.6
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/in-tcldom/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/in-tcldom/
COMMENT=	DOM implementation for use with TclXML or TclExpat

DEPENDS+=	tcl-xml-*:../../textproc/tcl-xml

# old name for this package...
CONFLICTS+=	TclDom-*

NO_CONFIGURE=
NO_BUILD=

do-install:
	${MKDIR} ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dom.tcl ${PREFIX}/lib/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dommap.tcl ${PREFIX}/lib/tcl/TclDOM
	${MKDIR} ${PREFIX}/share/doc/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/tcl/TclDOM
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/tcl/TclDOM

.include "../../mk/bsd.pkg.mk"
