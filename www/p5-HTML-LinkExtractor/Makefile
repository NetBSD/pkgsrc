# $NetBSD: Makefile,v 1.21 2015/06/12 10:52:00 wiz Exp $

DISTNAME=	HTML-LinkExtractor-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-LinkExtractor/
COMMENT=	Extract links from an HTML document

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=	auto/HTML/LinkExtractor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
