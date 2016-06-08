# $NetBSD: Makefile,v 1.2 2016/06/08 19:25:13 wiz Exp $

DISTNAME=	Plack-Middleware-MethodOverride-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DW/DWHEELER/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DW/DWHEELER/
COMMENT=	Override REST methods to Plack apps via POST
LICENSE=	${PERL5_LICENSE}

# url2pkg-marker (please do not remove this line.)
#PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=         auto/Plack/Middleware/MethodOverride/.packlist
USE_LANGUAGES=          # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
