# $NetBSD: Makefile,v 1.1.1.1 2000/08/21 18:44:08 jwise Exp $
#

DISTNAME=	TclDOM-1.6
CATEGORIES=	textproc www
MASTER_SITES=	http://www.zveno.com/in-tclxml/in-tcldom/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/in-tcldom/

DEPENDS+=	TclXML-*:../../textproc/tclxml

NO_CONFIGURE=
NO_BUILD=

do-install:
	${MKDIR} ${PREFIX}/lib/TclDOM
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dom.tcl ${PREFIX}/lib/TclDOM
	${INSTALL_DATA} ${WRKSRC}/dommap.tcl ${PREFIX}/lib/TclDOM
	${MKDIR} ${PREFIX}/share/doc/TclDOM
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/TclDOM
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/TclDOM

.include "../../mk/bsd.pkg.mk"
