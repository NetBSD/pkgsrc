# $NetBSD: Makefile,v 1.1.1.1 2000/08/21 18:08:22 jwise Exp $
#

DISTNAME=	TclXML-1.2
CATEGORIES=	textproc www
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/

NO_CONFIGURE=
NO_BUILD=

do-install:
	${MKDIR} ${PREFIX}/lib/TclXML
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/TclXML
	${INSTALL_DATA} ${WRKSRC}/sgml.tcl ${PREFIX}/lib/TclXML
	${INSTALL_DATA} ${WRKSRC}/xml.tcl ${PREFIX}/lib/TclXML
	${MKDIR} ${PREFIX}/share/doc/TclXML
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/TclXML
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/TclXML

.include "../../mk/bsd.pkg.mk"
