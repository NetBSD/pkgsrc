# $NetBSD: Makefile,v 1.8 2017/06/05 14:25:23 ryoon Exp $

DISTNAME=	Hijk-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/G/GU/GUGOD/

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
