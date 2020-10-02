# $NetBSD: Makefile,v 1.5 2020/10/02 11:59:37 wen Exp $

DISTNAME=	HTTP-CookieJar-0.010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://metacpan.org/dist/HTTP-CookiesiJar/
COMMENT=	Minimalist HTTP user agent cookie jar
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date>=0:../../www/p5-HTTP-Date
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep \
		p5-Test-Requires>=0:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/HTTP/CookieJar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
