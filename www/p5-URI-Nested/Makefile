# $NetBSD: Makefile,v 1.5 2016/06/08 19:25:17 wiz Exp $

DISTNAME=	URI-Nested-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide nested URIs
HOMEPAGE=	http://search.cpan.org/dist/URI-db/
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/URI/Nested/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
