# $NetBSD: Makefile,v 1.4 2019/06/30 20:17:47 nia Exp $

DISTNAME=	URI-ws-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI-ws
COMMENT=	WebSocket support for URI package
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/URI/ws/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
