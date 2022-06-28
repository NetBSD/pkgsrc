# $NetBSD: Makefile,v 1.21 2022/06/28 11:37:30 wiz Exp $

DISTNAME=	HTTP-Server-EV-0.69
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Server-EV
COMMENT=	Asynchronous HTTP server using EV event loop
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Coro-[0-9]*:../../devel/p5-Coro
DEPENDS+=	p5-File-Util-[0-9]*:../../devel/p5-File-Util
DEPENDS+=	p5-Guard-[0-9]*:../../devel/p5-Guard
DEPENDS+=	p5-IO-AIO-[0-9]*:../../devel/p5-IO-AIO
DEPENDS+=	p5-AnyEvent-AIO-[0-9]*:../../devel/p5-AnyEvent-AIO
# actually, test dependencies
BUILD_DEPENDS+=	p5-AnyEvent-HTTP-[0-9]*:../../www/p5-AnyEvent-HTTP
BUILD_DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

EXTRACT_USING=	bsdtar
PERL5_PACKLIST=	auto/HTTP/Server/EV/.packlist

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
