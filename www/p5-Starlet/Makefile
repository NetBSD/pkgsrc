# $NetBSD: Makefile,v 1.33 2026/10/31 14:00:10 wiz Exp $

DISTNAME=	Starlet-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KAZUHO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Starlet
COMMENT=	Perl 5 Plack based standalone HTTP/1.0 server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parallel-Prefork>=0.18:../../devel/p5-Parallel-Prefork
DEPENDS+=	p5-Plack>=0.992:../../www/p5-Plack
DEPENDS+=	p5-Server-Starter>=0.06:../../sysutils/p5-Server-Starter
TEST_DEPENDS+=	p5-Test-SharedFork>=0:../../devel/p5-Test-SharedFork
TEST_DEPENDS+=	p5-Test-TCP>=2.10:../../net/p5-Test-TCP

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Starlet/.packlist

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
