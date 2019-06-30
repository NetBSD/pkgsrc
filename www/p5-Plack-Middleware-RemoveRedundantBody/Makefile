# $NetBSD: Makefile,v 1.9 2019/06/30 20:17:41 nia Exp $

DISTNAME=	Plack-Middleware-RemoveRedundantBody-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-ReverseProxy
COMMENT=	Removes body for HTTP response if it's not required
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/RemoveRedundantBody/.packlist

DEPENDS+=	p5-Plack>=0:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
