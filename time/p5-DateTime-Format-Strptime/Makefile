# $NetBSD: Makefile,v 1.36 2019/08/11 13:24:08 wiz Exp $

DISTNAME=	DateTime-Format-Strptime-1.76
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-Strptime
COMMENT=	Perl 5 module to parse and format strp and strf time patterns
LICENSE=	artistic-2.0

DEPENDS+=	p5-DateTime>=1.00:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=1.05:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.79:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-ValidationCompiler>=0:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-Package-DeprecationManager>=0.15:../../devel/p5-Package-DeprecationManager
DEPENDS+=	p5-Specio>=0.33:../../devel/p5-Specio
# for make test
BUILD_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

PERL5_PACKLIST=		auto/DateTime/Format/Strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
