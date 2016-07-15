# $NetBSD: Makefile,v 1.58 2016/07/15 02:58:09 wen Exp $

DISTNAME=	DateTime-1.34
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	artistic-2.0

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-CPAN-Meta-Check>=0.11:../../devel/p5-CPAN-Meta-Check
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

DEPENDS+=	p5-DateTime-Locale>=1.05:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=2.00:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Math-Round-[0-9]*:../../math/p5-Math-Round

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
