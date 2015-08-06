# $NetBSD: Makefile,v 1.3 2015/08/06 09:12:20 wiz Exp $

DISTNAME=	Hijk-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AV/AVAR/
COMMENT=	Hijk - Fast & minimal low-level HTTP client
LICENSE=	mit

# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/Hijk/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
