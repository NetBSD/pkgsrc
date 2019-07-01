# $NetBSD: Makefile,v 1.7 2019/07/01 21:35:59 nia Exp $

DISTNAME=	Plack-Middleware-MethodOverride-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MI/MIYAGAWA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/D/DW/DWHEELER/
COMMENT=	Override REST methods to Plack apps via POST
LICENSE=	${PERL5_LICENSE}

DEPENDS=	p5-Plack>=0:../../www/p5-Plack

PERL5_PACKLIST=         auto/Plack/Middleware/MethodOverride/.packlist
USE_LANGUAGES=          # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
