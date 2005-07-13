# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:46 jlam Exp $

DISTNAME=	HTML-LinkExtractor-0.121
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~podmaster/${DISTNAME}/
COMMENT=	Extract links from an HTML document

PKG_INSTALLATION_TYPES=	overwrite pkgviews
EXTRACT_USING=		pax

PERL5_PACKLIST=	auto/HTML/LinkExtractor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
