# $NetBSD: Makefile,v 1.14 2005/10/25 13:40:24 wiz Exp $

DISTNAME=		HTML-TableExtract-2.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		damon@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/table-extract/
COMMENT=		Perl5 module to simplify extracting HTML tables

DEPENDS+=		p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Element-Extended>=1.13:../../www/p5-HTML-Element-Extended

PERL5_PACKLIST=		auto/HTML-TableExtract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
