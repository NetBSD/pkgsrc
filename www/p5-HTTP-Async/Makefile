# $NetBSD: Makefile,v 1.8 2014/02/23 13:15:11 wen Exp $

DISTNAME=	HTTP-Async-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Async/
COMMENT=	Lightweight HTTP client implementation
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-HTTP-Server-Simple>=0:../../www/p5-Test-HTTP-Server-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Async/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
