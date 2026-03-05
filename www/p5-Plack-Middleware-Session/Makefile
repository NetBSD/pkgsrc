# $NetBSD: Makefile,v 1.30 2026/03/05 09:35:27 wiz Exp $

DISTNAME=	Plack-Middleware-Session-0.36
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-Session
COMMENT=	Plack middleware for session management
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Plack>=0.9910:../../www/p5-Plack
DEPENDS+=	p5-Cookie-Baker>=0:../../www/p5-Cookie-Baker
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Crypt-SysRandom>=0:../../security/p5-Crypt-SysRandom

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork
TEST_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Plack/Middleware/Session/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
