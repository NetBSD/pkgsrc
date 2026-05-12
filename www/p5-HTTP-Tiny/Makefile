# $NetBSD: Makefile,v 1.31 2026/05/12 07:01:06 wiz Exp $

DISTNAME=		HTTP-Tiny-0.092
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/HTTP::Tiny
COMMENT=		Small, simple, correct HTTP/1.1 client
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTTP-CookieJar>=0.001:../../www/p5-HTTP-CookieJar
DEPENDS+=		p5-IO-Socket-SSL>=1.42:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Mozilla-CA>=20160104:../../security/p5-Mozilla-CA
DEPENDS+=		p5-Net-SSLeay>=1.49:../../security/p5-Net-SSLeay

PERL5_PACKLIST=		auto/HTTP/Tiny/.packlist
USE_LANGUAGES=		# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
