# $NetBSD: Makefile,v 1.10 2006/05/17 04:29:00 minskim Exp $
#

DISTNAME=	TclExpat-1.1
PKGNAME=	tcl-expat-1.1
PKGREVISION=	4
CATEGORIES=	textproc www tcl
MASTER_SITES=	http://www.zveno.com/in-tclxml/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.zveno.com/zm.cgi/in-tclxml/
COMMENT=	XML parser implemented entirely in Tcl

USE_LIBTOOL=	yes

MAKE_ENV+=	SHLIBTOOL=${SHLIBTOOL:Q}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tcl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/TclExpat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcl/TclExpat

.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
