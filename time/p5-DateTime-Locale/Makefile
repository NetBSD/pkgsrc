# $NetBSD: Makefile,v 1.2 2005/02/26 01:44:44 wiz Exp $

DISTNAME=	DateTime-Locale-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Localization data for p5-DateTime

DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_BUILDLINK3=	YES
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
