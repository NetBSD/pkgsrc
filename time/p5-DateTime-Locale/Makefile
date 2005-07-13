# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:44 jlam Exp $

DISTNAME=	DateTime-Locale-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Localization data for p5-DateTime

DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
