# $NetBSD: Makefile,v 1.20 2023/07/06 09:42:58 wiz Exp $

DISTNAME=	URI-db-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide database URIs
HOMEPAGE=	https://metacpan.org/release/URI-db
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-Nested>=0.10:../../www/p5-URI-Nested

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/URI/db/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
