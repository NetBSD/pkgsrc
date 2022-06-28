# $NetBSD: Makefile,v 1.24 2022/06/28 11:37:45 wiz Exp $

DISTNAME=		URI-Find-20160806
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/URI-Find
COMMENT=		Perl5 module to find URIs in arbitrary text
LICENSE=		${PERL5_LICENSE}

# requires URI::URL 5.00 - oldest available URI on CPAN contains 5.03
DEPENDS+=		p5-URI>=1.60:../../www/p5-URI

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/URI/Find/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
