# $NetBSD: Makefile,v 1.26 2018/08/29 06:06:34 wiz Exp $

DISTNAME=	DateTime-Format-Natural-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Natural/
COMMENT=	Create machine readable date/time with natural parsing logic
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate
DEPENDS+=	p5-boolean-[0-9]*:../../devel/p5-boolean
DEPENDS+=	p5-Module-Util>=0:../../devel/p5-Module-Util
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
# recommended
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

TEST_DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime

PERL5_MODULE_TYPE=  	Module::Build
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Natural/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
