# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:59 tv Exp $
#

DISTNAME=		HTML-StickyQuery-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sqy
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/search?dist=HTML-StickyQuery
COMMENT=		Add sticky QUERY_STRING to a tag href attributes

DEPENDS+=		p5-HTML-Parser>=3.34:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI>=1.27:../../www/p5-URI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/StickyQuery/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
