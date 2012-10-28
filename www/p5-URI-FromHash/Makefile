# $NetBSD: Makefile,v 1.6 2012/10/28 06:30:54 asau Exp $
#

DISTNAME=	URI-FromHash-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/URI/
COMMENT=	Build a URI from a set of named parameters

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-URI>0:../../www/p5-URI
DEPENDS+=	p5-Params-Validate>0:../../devel/p5-Params-Validate

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/URI/FromHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
