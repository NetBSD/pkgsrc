# $NetBSD: Makefile,v 1.10 2011/11/17 08:04:22 hiramatsu Exp $
#

DISTNAME=		HTML-StickyQuery-0.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5sqy
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/search?dist=HTML-StickyQuery
COMMENT=		Add sticky QUERY_STRING to a tag href attributes
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-HTML-Parser>=3.34:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI>=1.27:../../www/p5-URI

PERL5_PACKLIST=		auto/HTML/StickyQuery/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
