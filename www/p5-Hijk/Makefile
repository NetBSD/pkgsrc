# $NetBSD: Makefile,v 1.12 2019/08/11 13:24:48 wiz Exp $

DISTNAME=	Hijk-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/G/GU/GUGOD/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AV/AVAR/
COMMENT=	Hijk - Fast & minimal low-level HTTP client
LICENSE=	mit

# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
BUILD_DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
BUILD_DEPENDS+=	p5-Net-Server>=0:../../net/p5-Net-Server
BUILD_DEPENDS+=	p5-Plack>=0:../../www/p5-Plack

PERL5_PACKLIST=	auto/Hijk/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
