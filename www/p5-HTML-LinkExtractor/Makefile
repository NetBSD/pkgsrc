# $NetBSD: Makefile,v 1.8 2006/09/17 00:11:52 adrianp Exp $

DISTNAME=	HTML-LinkExtractor-0.121
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~podmaster/${DISTNAME}/
COMMENT=	Extract links from an HTML document

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
EXTRACT_USING=		pax

PERL5_PACKLIST=	auto/HTML/LinkExtractor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
