# $NetBSD: Makefile,v 1.10 2004/01/18 21:48:42 heinz Exp $

DISTNAME=		HTML-Format-2.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hfo
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Format/
COMMENT=		Perl5 modules for converting HTML to other text formats

DEPENDS+=		p5-Font-AFM>=1.18:../../fonts/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.15:../../www/p5-HTML-Tree

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
