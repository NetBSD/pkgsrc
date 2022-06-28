# $NetBSD: Makefile,v 1.22 2022/06/28 11:37:45 wiz Exp $

DISTNAME=	Twiggy-0.1025
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Twiggy
COMMENT=	AnyEvent HTTP server for PSGI
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Twiggy/.packlist

BUILD_DEPENDS+=	p5-Server-Starter-[0-9]*:../../sysutils/p5-Server-Starter
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-EV-[0-9]*:../../devel/p5-EV
DEPENDS+=	p5-HTTP-Parser-XS-[0-9]*:../../www/p5-HTTP-Parser-XS
DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Plack>=0.99:../../www/p5-Plack
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
