# $NetBSD: Makefile,v 1.2 2001/05/22 17:24:54 mjl Exp $

DISTNAME=		HTML-Mason-1.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.masonhq.com/
COMMENT=		Perl-based web site development and delivery system

DEPENDS+=               p5-MLDBM>=2.0:../../databases/p5-MLDBM
DEPENDS+=               p5-Params-Validate>=0.04:../../devel/p5-Params-Validate

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Mason/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
