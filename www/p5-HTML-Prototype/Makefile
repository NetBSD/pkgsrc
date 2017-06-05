# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:18 ryoon Exp $

DISTNAME=	HTML-Prototype-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Prototype
COMMENT=	Generate HTML and Javascript for the Prototype library

DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-HTML-Tree>=3.19.01:../../www/p5-HTML-Tree

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/HTML/Prototype/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
