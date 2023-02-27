# $NetBSD: Makefile,v 1.1 2023/02/27 18:13:34 nikita Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Mojolicious-Plugin-OAuth2-Server-0.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mojolicio.us/
COMMENT=	OAuth2 Authorization Server with Mojolicious
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Mojo-JWT-[0-9]*:../../www/p5-Mojo-JWT
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-Net-OAuth2-AuthorizationServer-[0-9]*:../../www/p5-Net-OAuth2-AuthorizationServer
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojolicious/Plugin/OAuth2/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
