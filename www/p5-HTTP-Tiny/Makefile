# $NetBSD: Makefile,v 1.23 2019/06/30 20:17:37 nia Exp $

DISTNAME=	HTTP-Tiny-0.076
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Tiny
COMMENT=	Perl5 module providing a small, simple, correct HTTP/1.1 client
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
TEST_DEPENDS+=	p5-Mozilla-CA>=0:../../security/p5-Mozilla-CA

PERL5_PACKLIST=		auto/HTTP/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
