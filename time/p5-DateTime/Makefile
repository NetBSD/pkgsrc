# $NetBSD: Makefile,v 1.84 2022/06/28 11:36:52 wiz Exp $

DISTNAME=	DateTime-1.58
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	artistic-2.0

DEPENDS+=	p5-DateTime-Locale>=1.06:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=2.02:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Math-Round-[0-9]*:../../math/p5-Math-Round
DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio
DEPENDS+=	p5-Params-ValidationCompiler>=0.11:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-namespace-autoclean>=0.19:../../devel/p5-namespace-autoclean

TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-CPAN-Meta-Check>=0.11:../../devel/p5-CPAN-Meta-Check
TEST_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class

PERL5_PACKLIST=	auto/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
