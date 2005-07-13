# $NetBSD: Makefile,v 1.17 2005/07/13 18:01:47 jlam Exp $

DISTNAME=		HTML-Tree-3.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htr
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Tree/
COMMENT=		Perl5 modules for manipulating HTML syntax trees

DEPENDS+=		p5-HTML-Parser>=2.19:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML-Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
