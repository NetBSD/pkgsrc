# $NetBSD: Makefile,v 1.3 1999/04/15 20:39:47 tron Exp $
#

DISTNAME=       	CGI_Lite-1.62.pm
PKGNAME=        	p5-CGI_Lite-1.62
NO_WRKSUBDIR=		YES
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}
EXTRACT_SUFX=		.gz

MAINTAINER=		bad@netbsd.org

USE_PERL5=		YES

EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} > CGI_Lite.pm

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKDIR}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
