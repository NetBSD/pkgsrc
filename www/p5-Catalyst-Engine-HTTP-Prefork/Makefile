# $NetBSD: Makefile,v 1.13 2023/07/06 09:42:27 wiz Exp $

DISTNAME=	Catalyst-Engine-HTTP-Prefork-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Engine-HTTP-Prefork
COMMENT=	High-performance pre-forking Catalyst engine
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Engine/HTTP/Prefork/.packlist

DEPENDS+=	p5-Catalyst-Runtime>=5.7012:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Cookie-XS>=0.08:../../www/p5-Cookie-XS
DEPENDS+=	p5-HTTP-Body>=1.01:../../www/p5-HTTP-Body
DEPENDS+=	p5-Net-Server>=0.97:../../net/p5-Net-Server
DEPENDS+=	p5-HTTP-HeaderParser-XS>=0.20:../../www/p5-HTTP-HeaderParser-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
