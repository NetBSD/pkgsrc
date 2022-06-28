# $NetBSD: Makefile,v 1.26 2022/06/28 11:37:24 wiz Exp $
#

DISTNAME=		HTML-StickyQuery-0.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/search?q=dist%3AHTML-StickyQuery
COMMENT=		Add sticky QUERY_STRING to a tag href attributes
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser>=3.34:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI>=1.27:../../www/p5-URI

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/HTML/StickyQuery/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
