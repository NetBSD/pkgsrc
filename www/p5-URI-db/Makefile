# $NetBSD: Makefile,v 1.7 2016/02/01 12:25:06 mef Exp $

DISTNAME=	URI-db-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide database URIs
HOMEPAGE=	http://search.cpan.org/dist/URI-db/
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-Nested>=0.10:../../www/p5-URI-Nested

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/URI/db/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
