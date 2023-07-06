# $NetBSD: Makefile,v 1.52 2023/07/06 09:42:38 wiz Exp $

DISTNAME=		HTML-Tree-5.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Tree
COMMENT=		Perl5 modules for manipulating HTML syntax trees
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser>=3.46:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset
# recommended, but result in circular dependency
#DEPENDS+=		p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
# recommended
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

# Build dependencies Encode, Test::More and base are in Perl5 core ...
TOOL_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=		p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
