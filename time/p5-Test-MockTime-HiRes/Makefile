# $NetBSD: Makefile,v 1.2 2023/07/06 09:42:15 wiz Exp $

DISTNAME=	Test-MockTime-HiRes-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::MockTime::HiRes
COMMENT=	Replaces actual time with simulated high resolution time
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-MockTime>=0:../../time/p5-Test-MockTime

TEST_DEPENDS=	p5-Test-Class>=0:../../devel/p5-Test-Class \
		p5-Test-Requires>=0:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Test/MockTime/HiRes/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
