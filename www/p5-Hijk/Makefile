# $NetBSD: Makefile,v 1.6 2016/06/08 19:25:08 wiz Exp $

DISTNAME=	Hijk-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/
COMMENT=	Hijk - Fast & minimal low-level HTTP client
LICENSE=	mit

# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
BUILD_DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Hijk/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
