# $NetBSD: Makefile,v 1.16 2016/06/08 19:24:49 wiz Exp $

DISTNAME=	DateTime-Format-Flexible-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Flexible/
COMMENT=	Flexibly parse strings and turn them into DateTime objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.7400:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

BUILD_DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime

USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Flexible/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
