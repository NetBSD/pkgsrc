# $NetBSD: Makefile,v 1.10 2004/01/20 12:28:00 agc Exp $
#

DISTNAME=	cgi.tcl
PKGNAME=	tcl-cgi-1.3.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://expect.nist.gov/cgi.tcl/
COMMENT=	Library of Tcl procedures to assist in writing CGI scripts

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

WRKSRC=		${WRKDIR}/cgi.tcl-1.3
DIST_SUBDIR=	${PKGNAME}

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcl/cgi-tcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/tcl/cgi-tcl

.include "../../mk/bsd.pkg.mk"
