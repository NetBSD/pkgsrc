# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:48 tron Exp $
#

PKGNAME=        	p5-HTML-Parser-2.22
DISTNAME!=       	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
