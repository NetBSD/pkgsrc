# $NetBSD: Makefile,v 1.25 2013/05/31 12:42:41 wiz Exp $

DISTNAME=		HTML-Format-2.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5hfo
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Format/
COMMENT=		Perl5 modules for converting HTML to other text formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Font-AFM>=1.18:../../fonts/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.15:../../www/p5-HTML-Tree

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
