# $NetBSD: Makefile,v 1.30 2024/04/07 21:34:46 wiz Exp $

DISTNAME=	HTTP-Body-1.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Body
COMMENT=	HTTP Body Parser
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTTP/Body/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
