# $NetBSD: Makefile,v 1.4 2001/02/25 04:18:18 hubertf Exp $
#

DISTNAME=	TclXML-1.2
PKGNAME=	tcl-xml-1.2
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

DEPENDS+=       tcl>=8.3.2:../../lang/tcl

# old name for this package...
CONFLICTS+=	TclXML-*

NO_CONFIGURE=
NO_BUILD=

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/sgml.tcl ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/xml.tcl ${PREFIX}/lib/tcl/TclXML
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/docs/reference.html ${PREFIX}/share/doc/tcl/TclXML
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/share/doc/tcl/TclXML

.include "../../mk/bsd.pkg.mk"
