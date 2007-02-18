# $NetBSD: Makefile,v 1.22 2007/02/18 03:17:10 wiz Exp $

DISTNAME=		HTML-Tree-3.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htr
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Tree/
COMMENT=		Perl5 modules for manipulating HTML syntax trees

DEPENDS+=		p5-HTML-Parser>=3.46:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML-Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
