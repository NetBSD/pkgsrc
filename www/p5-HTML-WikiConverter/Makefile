# $NetBSD: Makefile,v 1.21 2022/06/28 11:37:26 wiz Exp $
#

DISTNAME=	HTML-WikiConverter-0.68
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-WikiConverter
COMMENT=	Convert HTML to wiki markup
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-CSS>=1.07:../../www/p5-CSS
DEPENDS+=	p5-HTML-Parser>=1.27:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset>=3.04:../../www/p5-HTML-Tagset
DEPENDS+=	p5-HTML-Tree>=3.18:../../www/p5-HTML-Tree
DEPENDS+=	p5-Params-Validate>=0.77:../../devel/p5-Params-Validate
DEPENDS+=	p5-URI>=1.35:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/WikiConverter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
