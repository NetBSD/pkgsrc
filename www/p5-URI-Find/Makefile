# $NetBSD: Makefile,v 1.2 2009/09/11 17:12:13 joerg Exp $
#

DISTNAME=		URI-Find-20090319
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/URI-Find/
COMMENT=		Perl5 module to find URIs in arbitrary text
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-URI>=1.00:../../www/p5-URI
BUILD_REQUIRES+=	p5-Test-Simple>=0.82:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/URI/Find/.packlist
PERL5_MODULE_TYPE=	Module::Build

BUILD_DEPENDS+=		p5-Module-Build>=0.30000:../../devel/p5-Module-Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
