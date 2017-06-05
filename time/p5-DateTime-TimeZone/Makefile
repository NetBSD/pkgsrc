# $NetBSD: Makefile,v 1.90 2017/06/05 14:25:04 ryoon Exp $

DISTNAME=	DateTime-TimeZone-2.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
DEPENDS+=	p5-List-AllUtils>=0:../../devel/p5-List-AllUtils
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=       p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler
DEPENDS+=       p5-Specio-[0-9]*:../../devel/p5-Specio

# for tests, but can't depend in it, since it depends on this package
#BUILD_DEPENDS+=	p5-DateTime>=0.1501:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Taint-[0-9]*:../../devel/p5-Test-Taint
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

# on HPUX it requires ../../time/p5-DateTime-TimeZone-HPUX
# but this will result in a circular dependency

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/TimeZone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
