# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:44 tv Exp $

DISTNAME=	DateTime-Locale-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Localization data for p5-DateTime

DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
