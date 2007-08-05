# $NetBSD: Makefile,v 1.1.1.1 2007/08/05 05:54:29 obache Exp $

DISTNAME=	Template-Multilingual-0.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tml
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Multilingual/
COMMENT=	Subclass of Template Toolkit supporting multilingual templates

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

PERL5_PACKLIST=	auto/Template/Multilingual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
