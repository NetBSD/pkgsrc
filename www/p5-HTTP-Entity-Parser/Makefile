# $NetBSD: Makefile,v 1.1 2016/10/01 13:01:58 wen Exp $

DISTNAME=	HTTP-Entity-Parser-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Entity-Parser/
COMMENT=	PSGI compliant HTTP Entity Parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-WWW-Form-UrlEncoded>=0.23:../../www/p5-WWW-Form-UrlEncoded
DEPENDS+=	p5-HTTP-MultiPartParser>=0:../../www/p5-HTTP-MultiPartParser

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTTP/Entity/Parser/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
