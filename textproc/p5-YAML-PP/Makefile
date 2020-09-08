# $NetBSD: Makefile,v 1.6 2020/09/08 13:09:59 wiz Exp $

DISTNAME=		YAML-PP-0.024
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		https://cpan.metacpan.org/authors/id/T/TI/TINITA/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/YAML::PP
COMMENT=		Modern, modular YAML processor
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/YAML/PP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
