# $NetBSD: Makefile,v 1.1.1.1 1999/01/11 22:22:50 kim Exp $
#

PKGNAME=        	p5-HTML-Parser-2.22
DISTNAME!=       	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=		packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
