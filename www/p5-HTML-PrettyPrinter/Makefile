# $NetBSD: Makefile,v 1.9 2004/04/24 22:46:13 jlam Exp $

DISTNAME=		HTML-PrettyPrinter-0.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpre
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for pretty-printing HTML

DEPENDS+=		p5-HTML-Tree>=3.0:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/PrettyPrinter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
