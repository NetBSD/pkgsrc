# $NetBSD: Makefile,v 1.36 2019/08/11 13:24:38 wiz Exp $

DISTNAME=		HTML-Format-2.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NIGELM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Format
COMMENT=		Perl5 modules for converting HTML to other text formats
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Font-AFM>=1.18:../../fonts/p5-Font-AFM
DEPENDS+=		p5-HTML-Tree>=3.15:../../www/p5-HTML-Tree

BUILD_DEPENDS+=		p5-File-Slurper-[0-9]*:../../devel/p5-File-Slurper
BUILD_DEPENDS+=		p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
BUILD_DEPENDS+=		p5-Test-EOL-[0-9]*:../../devel/p5-Test-EOL
BUILD_DEPENDS+=		p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
