# $NetBSD: Makefile,v 1.7 2001/02/25 04:18:24 hubertf Exp $
#

DISTNAME=	cgi.tcl
PKGNAME=	tcl-cgi-1.3.0
WRKSRC=		${WRKDIR}/cgi.tcl-1.3
CATEGORIES=	www
MASTER_SITES=	http://expect.nist.gov/cgi.tcl/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://expect.nist.gov/cgi.tcl/
COMMENT=	Library of Tcl procedures to assist in writing CGI scripts

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

DIST_SUBDIR=	${PKGNAME}

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/cgi-tcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/tcl/cgi-tcl

.include "../../mk/bsd.pkg.mk"
