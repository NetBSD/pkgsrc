# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:52 grant Exp $
#

DISTNAME=	TclExpat-1.1
PKGNAME=	tcl-expat-1.1
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

DEPENDS+=       tcl>=8.3.2:../../lang/tcl
DEPENDS+=	expat-[0-9]*:../../textproc/expat

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclExpat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcl/TclExpat

.include "../../mk/bsd.pkg.mk"
