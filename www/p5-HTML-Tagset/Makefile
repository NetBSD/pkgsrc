# $NetBSD: Makefile,v 1.3 2000/12/04 01:52:54 tv Exp $
#

DISTNAME=		HTML-Tagset-3.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Tagset/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
