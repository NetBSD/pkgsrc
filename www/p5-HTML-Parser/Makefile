# $NetBSD: Makefile,v 1.22.2.1 2003/12/05 17:22:45 agc Exp $
#

DISTNAME=		HTML-Parser-3.34
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpa
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/GAAS/HTML-Parser/
COMMENT=		Perl5 module to parse HTML text documents

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
