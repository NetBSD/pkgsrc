# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:48 tron Exp $
#

DISTNAME=       	FCGI-0.42
PKGNAME=        	p5-FCGI-0.42
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
