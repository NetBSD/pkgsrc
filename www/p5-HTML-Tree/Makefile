# $NetBSD: Makefile,v 1.19 2006/01/01 23:11:38 wiz Exp $

DISTNAME=		HTML-Tree-3.1901
#PKGNAME=		p5-${DISTNAME}
PKGNAME=		p5-HTML-Tree-3.19.01
SVR4_PKGNAME=		p5htr
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
