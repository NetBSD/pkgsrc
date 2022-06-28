# $NetBSD: Makefile,v 1.64 2022/06/28 11:36:55 wiz Exp $

DISTNAME=	DateTime-Locale-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Locale
COMMENT=	Localization data for p5-DateTime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Params-ValidationCompiler>=0.13:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-Scalar-List-Utils>=1.45:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio
DEPENDS+=	p5-namespace-autoclean>=0.19:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.03:../../devel/p5-File-ShareDir-Install

TEST_DEPENDS+=	p5-CPAN-Meta-Check>=0.011:../../devel/p5-CPAN-Meta-Check
TEST_DEPENDS+=	p5-IPC-System-Simple>=0:../../devel/p5-IPC-System-Simple
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
TEST_DEPENDS+=	p5-Test-File-ShareDir-[0-9]*:../../devel/p5-Test-File-ShareDir
#TEST_DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
#TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
#TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
