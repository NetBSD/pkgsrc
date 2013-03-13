# $NetBSD: Makefile,v 1.46 2013/03/13 14:11:50 wen Exp $

DISTNAME=	DateTime-TimeZone-1.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Singleton>=1.03:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load
DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
# for tests, but can't depend in it, since it depends on this package
#BUILD_DEPENDS+=	p5-DateTime>=0.1501:../../time/p5-DateTime

# on HPUX it requires ../../time/p5-DateTime-TimeZone-HPUX
# but this will result in circular dependency

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/TimeZone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
