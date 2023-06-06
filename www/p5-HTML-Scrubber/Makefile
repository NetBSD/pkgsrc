# $NetBSD: Makefile,v 1.32 2023/06/06 12:42:43 riastradh Exp $
#

DISTNAME=	HTML-Scrubber-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Parser>=3.47:../../www/p5-HTML-Parser
TOOL_DEPENDS+=	p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs

# for make test
TOOL_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
TOOL_DEPENDS+=	p5-Test-EOL-[0-9]*:../../devel/p5-Test-EOL
TOOL_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Scrubber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
