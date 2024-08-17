# $NetBSD: Makefile,v 1.24 2024/08/17 09:25:36 wiz Exp $

DISTNAME=	Plack-Middleware-Deflater-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-Deflater
COMMENT=	Plack middleware to compress response body with Gzip or Deflate
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-IO-Handle-Util-[0-9]*:../../devel/p5-IO-Handle-Util
# also needs Test::SharedFork

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Plack/Middleware/Deflater/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
