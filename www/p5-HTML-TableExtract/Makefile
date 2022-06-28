# $NetBSD: Makefile,v 1.39 2022/06/28 11:37:25 wiz Exp $

DISTNAME=		HTML-TableExtract-2.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-TableExtract
COMMENT=		Perl5 module to simplify extracting HTML tables
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Element-Extended>=1.16:../../www/p5-HTML-Element-Extended

USE_LANGUAGES=		# empty

# one test failure as of 2.15
# https://github.com/mojotoad/HTML-TableExtract/issues/2

PERL5_PACKLIST=		auto/HTML-TableExtract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
