# $NetBSD: Makefile,v 1.3 2019/08/11 13:24:44 wiz Exp $

DISTNAME=	HTTP-CookieJar-0.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://metacpan.org/dist/HTTP-CookiesiJar/
COMMENT=	Minimalist HTTP user agent cookie jar
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message
DEPENDS+=	p5-HTTP-Date>=0:../../www/p5-HTTP-Date

PERL5_PACKLIST=		auto/HTTP/CookieJar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
