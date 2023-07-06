# $NetBSD: Makefile,v 1.24 2023/07/06 09:42:38 wiz Exp $

DISTNAME=	HTTP-Async-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Async
COMMENT=	Lightweight HTTP client implementation
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-HTTP-Server-Simple>=0:../../www/p5-Test-HTTP-Server-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Async/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
