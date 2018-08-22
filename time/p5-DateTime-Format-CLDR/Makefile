# $NetBSD: Makefile,v 1.6 2018/08/22 09:47:16 wiz Exp $

DISTNAME=	DateTime-Format-CLDR-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MA/MAROS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MA/MAROS/
COMMENT=	Parse and format CLDR, Common Locale Date Repository, time patterns
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-DateTime-Event-Recurrence-[0-9]*:../../time/p5-DateTime-Event-Recurrence
BUILD_DEPENDS+=	p5-DateTime-Set-[0-9]*:../../time/p5-DateTime-Set
BUILD_DEPENDS+=	p5-DateTime-Incomplete-[0-9]*:../../time/p5-DateTime-Incomplete
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/DateTime/Format/CLDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
