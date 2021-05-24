# $NetBSD: Makefile,v 1.19 2021/05/24 19:55:07 wiz Exp $

DISTNAME=	Test-MockTime-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::MockTime
COMMENT=	Replaces actual time with simulated time
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/Test/MockTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
