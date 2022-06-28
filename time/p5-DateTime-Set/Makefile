# $NetBSD: Makefile,v 1.32 2022/06/28 11:36:56 wiz Exp $

DISTNAME=	DateTime-Set-0.3900
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Set
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.12:../../time/p5-DateTime
DEPENDS+=	p5-Set-Infinite>=0.59:../../math/p5-Set-Infinite
# ChangeLog for 0.3900 mentions this dependency
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

# for make test
BUILD_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class

PERL5_PACKLIST=	auto/DateTime/Set/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
