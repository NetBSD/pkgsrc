# $NetBSD: Makefile,v 1.14 2004/04/25 05:53:05 minskim Exp $

DISTNAME=		HTML-Tree-3.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htr
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Tree/
COMMENT=		Perl5 modules for manipulating HTML syntax trees

DEPENDS+=		p5-HTML-Parser>=2.19:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML-Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
