# $NetBSD: Makefile,v 1.7 2004/04/27 05:44:23 snj Exp $

DISTNAME=		HTML-TableExtract-1.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		damon@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/table-extract/
COMMENT=		Perl5 module to simplify extracting HTML tables

DEPENDS+=		p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-TableExtract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
