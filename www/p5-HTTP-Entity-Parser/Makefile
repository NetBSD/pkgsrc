# $NetBSD: Makefile,v 1.17 2022/06/28 11:37:28 wiz Exp $

DISTNAME=	HTTP-Entity-Parser-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Entity-Parser
COMMENT=	PSGI compliant HTTP Entity Parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-WWW-Form-UrlEncoded>=0.23:../../www/p5-WWW-Form-UrlEncoded
DEPENDS+=	p5-HTTP-MultiPartParser>=0:../../www/p5-HTTP-MultiPartParser
DEPENDS+=	p5-Hash-MultiValue-[0-9]*:../../devel/p5-Hash-MultiValue
DEPENDS+=	p5-Stream-Buffered-[0-9]*:../../devel/p5-Stream-Buffered

TEST_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
TEST_DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTTP/Entity/Parser/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
