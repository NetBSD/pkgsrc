# $NetBSD: Makefile,v 1.51 2018/08/22 09:47:17 wiz Exp $

DISTNAME=	DateTime-Locale-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Locale/
COMMENT=	Localization data for p5-DateTime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Params-ValidationCompiler>=0.13:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-Scalar-List-Utils>=1.45:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio
DEPENDS+=	p5-namespace-autoclean>=0.19:../../devel/p5-namespace-autoclean

# for make test
BUILD_DEPENDS+=	p5-CPAN-Meta-Check>=0.011:../../devel/p5-CPAN-Meta-Check
BUILD_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-File-ShareDir-[0-9]*:../../devel/p5-Test-File-ShareDir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
