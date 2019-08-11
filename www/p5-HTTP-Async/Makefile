# $NetBSD: Makefile,v 1.19 2019/08/11 13:24:43 wiz Exp $

DISTNAME=	HTTP-Async-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Async
COMMENT=	Lightweight HTTP client implementation
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-HTTP-Server-Simple>=0:../../www/p5-Test-HTTP-Server-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Async/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
