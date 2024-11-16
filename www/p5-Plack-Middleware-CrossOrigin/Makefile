# $NetBSD: Makefile,v 1.3 2024/11/16 12:07:56 wiz Exp $

DISTNAME=	Plack-Middleware-CrossOrigin-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Plack::Middleware::CrossOrigin
COMMENT=	Adds headers to allow Cross-Origin Resource Sharing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Plack/Middleware/CrossOrigin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
