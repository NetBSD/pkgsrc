# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:18 ryoon Exp $

DISTNAME=	HTML-Prototype-Useful-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Prototype-Useful
COMMENT=	Some useful additions for the Prototype library

DEPENDS+=	p5-HTML-Prototype>=1.32:../../www/p5-HTML-Prototype

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=	auto/HTML/Prototype/Useful/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
