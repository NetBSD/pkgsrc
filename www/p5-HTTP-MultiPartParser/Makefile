# $NetBSD: Makefile,v 1.10 2022/06/28 11:37:29 wiz Exp $

DISTNAME=	HTTP-MultiPartParser-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-MultiPartParser
COMMENT=	HTTP MultiPart Parser
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTTP/MultiPartParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
