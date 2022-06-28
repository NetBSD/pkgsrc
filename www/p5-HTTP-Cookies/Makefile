# $NetBSD: Makefile,v 1.24 2022/06/28 11:37:27 wiz Exp $

DISTNAME=	HTTP-Cookies-6.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Cookies
COMMENT=	HTTP cookie jars
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date

PERL5_PACKLIST=		auto/HTTP/Cookies/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
