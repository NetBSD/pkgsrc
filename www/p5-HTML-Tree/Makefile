# $NetBSD: Makefile,v 1.7 2002/10/27 20:48:56 seb Exp $

DISTNAME=		HTML-Tree-3.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htr
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 modules for manipulating HTML syntax trees

DEPENDS+=		p5-HTML-Parser>=2.19:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
