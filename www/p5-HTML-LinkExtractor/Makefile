# $NetBSD: Makefile,v 1.28 2021/05/24 19:55:31 wiz Exp $

DISTNAME=	HTML-LinkExtractor-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-LinkExtractor
COMMENT=	Extract links from an HTML document

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=	auto/HTML/LinkExtractor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
