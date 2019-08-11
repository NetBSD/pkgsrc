# $NetBSD: Makefile,v 1.21 2019/08/11 13:24:05 wiz Exp $

DISTNAME=	DateTime-Format-Builder-0.82
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-Builder
COMMENT=	Create DateTime parser classes and objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=1.00:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime>=1.04:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
# for make test
BUILD_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
BUILD_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/Format/Builder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
