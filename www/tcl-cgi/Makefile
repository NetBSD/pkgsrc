# $NetBSD: Makefile,v 1.5 2001/01/24 18:44:59 he Exp $
#

DISTNAME=	cgi.tcl
PKGNAME=	tcl-cgi-1.3.0
WRKSRC=		${WRKDIR}/cgi.tcl-1.3
CATEGORIES=	www
MASTER_SITES=	http://expect.nist.gov/cgi.tcl/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://expect.nist.gov/cgi.tcl/

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

DIST_SUBDIR=	${PKGNAME}

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/tcl/cgi-tcl
	${MKDIR} ${PREFIX}/share/examples/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tcl/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/tcl/cgi-tcl

.include "../../mk/bsd.pkg.mk"
