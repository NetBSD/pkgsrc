# $NetBSD: Makefile,v 1.26 2024/01/04 10:51:25 wiz Exp $

DISTNAME=	HTTP-Cookies-6.11
PKGNAME=	p5-${DISTNAME}
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
