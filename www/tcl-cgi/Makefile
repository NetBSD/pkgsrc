# $NetBSD: Makefile,v 1.2 1999/07/07 16:10:42 bouyer Exp $
#

DISTNAME=	cgi.tcl
PKGNAME=	tcl-cgi-0.8
WRKSRC=		${WRKDIR}/cgi.tcl-0.8
CATEGORIES=	www
MASTER_SITES=	http://expect.nist.gov/cgi.tcl/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://expect.nist.gov/cgi.tcl/

DEPENDS+=	tcl-8.0.5:../../lang/tcl80

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/cgi-tcl
	${MKDIR} ${PREFIX}/share/examples/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/cgi-tcl
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/cgi-tcl

.include "../../mk/bsd.pkg.mk"
