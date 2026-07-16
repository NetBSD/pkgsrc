# $NetBSD: Makefile,v 1.16.8.1 2026/07/16 14:17:28 maya Exp $

DISTNAME=	YAML-PP-v0.41.0
PKGNAME=	p5-${DISTNAME:S/v//}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TI/TINITA/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/YAML::PP
COMMENT=		Modern, modular YAML processor
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=		p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/YAML/PP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
