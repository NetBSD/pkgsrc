# $NetBSD: Makefile,v 1.7 2013/05/31 12:42:49 wiz Exp $

DISTNAME=	Plack-App-Proxy-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-App-Proxy/
COMMENT=	Plack middleware proxy application
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/App/Proxy/.packlist

BUILD_DEPENDS+=	p5-Test-Simple>=0.88:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
DEPENDS+=	p5-AnyEvent-HTTP>=1.44:../../www/p5-AnyEvent-HTTP
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Plack>=0.9913:../../www/p5-Plack

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
