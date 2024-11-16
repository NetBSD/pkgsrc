# $NetBSD: Makefile,v 1.23 2024/11/16 12:07:21 wiz Exp $

DISTNAME=	Test-MockTime-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::MockTime
COMMENT=	Replaces actual time with simulated time
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/Test/MockTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
