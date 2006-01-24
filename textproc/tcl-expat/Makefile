# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=	TclExpat-1.1
PKGNAME=	tcl-expat-1.1
PKGREVISION=	2
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclExpat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcl/TclExpat

.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
