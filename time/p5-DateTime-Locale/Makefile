# $NetBSD: Makefile,v 1.33 2016/06/30 17:44:01 wiz Exp $

DISTNAME=	DateTime-Locale-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Locale/
COMMENT=	Localization data for p5-DateTime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Dist-CheckConflicts-[0-9]*:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-Validate>=0.91:../../devel/p5-Params-Validate
DEPENDS+=	p5-Scalar-List-Utils>=1.45:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
