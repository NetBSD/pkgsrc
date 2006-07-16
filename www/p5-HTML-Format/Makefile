# $NetBSD: Makefile,v 1.17 2006/07/16 13:31:31 heinz Exp $

DISTNAME=		HTML-Format-2.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hfo
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Format/
COMMENT=		Perl5 modules for converting HTML to other text formats

DEPENDS+=		p5-Font-AFM>=1.18:../../fonts/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.15:../../www/p5-HTML-Tree

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML-Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
