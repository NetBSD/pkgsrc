# $NetBSD: Makefile,v 1.8 2001/05/03 14:03:37 agc Exp $
#

DISTNAME=	cgi.tcl
PKGNAME=	tcl-cgi-1.3.0
WRKSRC=		${WRKDIR}/cgi.tcl-1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_BACKUP}

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
