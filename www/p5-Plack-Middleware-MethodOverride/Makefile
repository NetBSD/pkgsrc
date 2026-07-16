# $NetBSD: Makefile,v 1.18 2026/07/16 19:06:14 wiz Exp $

DISTNAME=	Plack-Middleware-MethodOverride-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Plack::Middleware::MethodOverride
COMMENT=	Override REST methods to Plack apps via POST
LICENSE=	${PERL5_LICENSE}

DEPENDS=	p5-Plack>=0:../../www/p5-Plack

PERL5_PACKLIST=		auto/Plack/Middleware/MethodOverride/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
