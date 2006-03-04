# $NetBSD: Makefile,v 1.20 2006/03/04 21:31:02 jlam Exp $

DISTNAME=		HTML-Tree-3.1901
#PKGNAME=		p5-${DISTNAME}
PKGNAME=		p5-HTML-Tree-3.19.01
SVR4_PKGNAME=		p5htr
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Tree/
COMMENT=		Perl5 modules for manipulating HTML syntax trees

DEPENDS+=		p5-HTML-Parser>=2.19:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML-Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
