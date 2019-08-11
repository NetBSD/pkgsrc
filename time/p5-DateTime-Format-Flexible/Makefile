# $NetBSD: Makefile,v 1.24 2019/08/11 13:24:06 wiz Exp $

DISTNAME=	DateTime-Format-Flexible-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-Flexible
COMMENT=	Flexibly parse strings and turn them into DateTime objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.7400:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Flexible/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
