# $NetBSD: Makefile,v 1.2 2014/05/29 23:38:16 wiz Exp $

DISTNAME=	URI-db-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide database URIs
HOMEPAGE=	http://search.cpan.org/dist/URI-db/
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-Nested-[0-9]*:../../www/p5-URI-Nested

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/URI/db/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
