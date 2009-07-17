# $NetBSD: Makefile,v 1.13 2009/07/17 18:00:26 adrianp Exp $

DISTNAME=	HTML-LinkExtractor-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-LinkExtractor/
COMMENT=	Extract links from an HTML document

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=	auto/HTML/LinkExtractor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
