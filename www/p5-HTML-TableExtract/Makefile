# $NetBSD: Makefile,v 1.3 2002/10/20 23:35:09 seb Exp $

DISTNAME=		HTML-TableExtract-1.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		damon@netbsd.org
HOMEPAGE=		http://sourceforge.net/projects/table-extract/
COMMENT=		perl5 module to simplify extracting HTML tables

DEPENDS+=		p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-TableExtract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
