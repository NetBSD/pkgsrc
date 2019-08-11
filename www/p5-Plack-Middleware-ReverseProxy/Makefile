# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:57 wiz Exp $

DISTNAME=	Plack-Middleware-ReverseProxy-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack-Middleware-ReverseProxy
COMMENT=	Plack middleware to support reverse proxy
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/ReverseProxy/.packlist

DEPENDS+=	p5-Plack>=0.9988:../../www/p5-Plack
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
