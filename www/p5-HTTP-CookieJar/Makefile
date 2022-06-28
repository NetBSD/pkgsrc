# $NetBSD: Makefile,v 1.9 2022/06/28 11:37:27 wiz Exp $

DISTNAME=	HTTP-CookieJar-0.012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://metacpan.org/dist/HTTP-CookiesiJar/
COMMENT=	Minimalist HTTP user agent cookie jar
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=	auto/HTTP/CookieJar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
