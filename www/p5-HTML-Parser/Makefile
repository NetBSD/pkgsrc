# $NetBSD: Makefile,v 1.3 1999/12/01 16:59:01 rh Exp $
#

PKGNAME=        	p5-HTML-Parser-2.25
DISTNAME!=       	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
