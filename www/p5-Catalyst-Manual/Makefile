# $NetBSD: Makefile,v 1.35 2023/07/06 09:42:27 wiz Exp $

DISTNAME=	Catalyst-Manual-5.9011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Manual
COMMENT=	Manual for Catalyst
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Catalyst/Manual/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
