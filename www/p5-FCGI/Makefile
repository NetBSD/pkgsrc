# $NetBSD: Makefile,v 1.4 2000/08/27 07:11:24 jlam Exp $
#

DISTNAME=       	FCGI-0.48
PKGNAME=        	p5-FCGI-0.48
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FCGI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
