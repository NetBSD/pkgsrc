# $NetBSD: Makefile,v 1.23 2022/06/28 11:36:56 wiz Exp $

DISTNAME=	MooseX-Types-DateTime-ButMaintained-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-DateTime-ButMaintained
COMMENT=	DateTime related constraints and coercions for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.4302:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.42:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.96:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Moose>=0.41:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Olson-Abbreviations>=0.03:../../time/p5-Olson-Abbreviations
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/DateTime/ButMaintained/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
