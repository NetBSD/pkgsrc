# $NetBSD: Makefile,v 1.1.1.1 2004/04/12 18:16:15 kim Exp $

DISTNAME=	ExtUtils-XSBuilder-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exs
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for automatic XS glue code generation

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/XSBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
