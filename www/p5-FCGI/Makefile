# $NetBSD: Makefile,v 1.3 1999/12/01 16:39:32 rh Exp $
#

DISTNAME=       	FCGI-0.48
PKGNAME=        	p5-FCGI-0.48
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
