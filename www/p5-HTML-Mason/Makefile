# $NetBSD: Makefile,v 1.12 2004/12/05 18:19:26 he Exp $

DISTNAME=		HTML-Mason-1.28
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hma
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.masonhq.com/
COMMENT=		Perl-based web site development and delivery system

DEPENDS+=               p5-MLDBM>=2.0:../../databases/p5-MLDBM
DEPENDS+=               p5-Params-Validate>=0.04:../../devel/p5-Params-Validate
DEPENDS+=		p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=		p5-Class-Container>=0.10:../../devel/p5-Class-Container
DEPENDS+=		p5-libapreq>=0.32:../../www/p5-libapreq

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Mason/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
