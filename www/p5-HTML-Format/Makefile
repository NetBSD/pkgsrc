# $NetBSD: Makefile,v 1.30 2015/06/12 10:52:00 wiz Exp $

DISTNAME=		HTML-Format-2.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Format/
COMMENT=		Perl5 modules for converting HTML to other text formats
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Font-AFM>=1.18:../../fonts/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.15:../../www/p5-HTML-Tree

BUILD_DEPENDS+=		p5-File-Slurp>=0:../../devel/p5-File-Slurp

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
