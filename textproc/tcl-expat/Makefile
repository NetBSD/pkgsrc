# $NetBSD: Makefile,v 1.1.1.1 2001/09/28 23:37:09 jwise Exp $
#

DISTNAME=	TclExpat-1.1
PKGNAME=	tcl-expat-1.1
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

DEPENDS+=       tcl>=8.3.2:../../lang/tcl
DEPENDS+=	expat-[0-9]*:../../textproc/expat

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclExpat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcl/TclExpat

.include "../../mk/bsd.pkg.mk"
