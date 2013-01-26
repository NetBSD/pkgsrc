# $NetBSD: Makefile,v 1.17 2013/01/26 20:24:46 rhaen Exp $

DISTNAME=	Catalyst-Manual-5.9006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Manual/
COMMENT=	Manual for Catalyst
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Catalyst/Manual/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
