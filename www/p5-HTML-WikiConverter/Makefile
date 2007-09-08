# $NetBSD: Makefile,v 1.1.1.1 2007/09/08 18:43:23 wiz Exp $
#

DISTNAME=	HTML-WikiConverter-0.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-WikiConverter/
COMMENT=	Convert HTML to wiki markup

DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate
DEPENDS+=	p5-CSS-[0-9]*:../../www/p5-CSS
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/WikiConverter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
