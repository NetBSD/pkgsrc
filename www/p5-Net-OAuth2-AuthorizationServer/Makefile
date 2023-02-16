# $NetBSD: Makefile,v 1.1 2023/02/16 19:51:21 nikita Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Net-OAuth2-AuthorizationServer-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AWS/LEEJO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::OAuth2::AuthorizationServer
COMMENT=	Easier implementation of an OAuth2 Authorization Server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CryptX-[0-9]*:../../security/p5-CryptX
DEPENDS+=	p5-Crypt-JWT-[0-9]*:../../security/p5-Crypt-JWT
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
TEST_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Net/OAuth2/AuthorizationServer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
