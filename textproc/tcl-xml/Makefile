# $NetBSD: Makefile,v 1.1.1.1 2000/08/30 19:46:37 jwise Exp $
#

DISTNAME=	TclXML-1.2
PKGNAME=	tcl-xml-1.2
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/

DEPENDS+=       tcl-8.3.2:../../lang/tcl

# old name for this package...
CONFLICTS+=	TclXML-*

NO_CONFIGURE=
NO_BUILD=

do-install:
	${MKDIR} ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/sgml.tcl ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/xml.tcl ${PREFIX}/lib/tcl/TclXML
	${MKDIR} ${PREFIX}/share/doc/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/tcl/TclXML

.include "../../mk/bsd.pkg.mk"
