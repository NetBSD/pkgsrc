# $NetBSD: Makefile,v 1.26 2025/07/04 08:48:55 wiz Exp $

DISTNAME=	Alien-GvaScript-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-GvaScript
COMMENT=	Gva extension to the prototype javascript framework
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Alien/GvaScript/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
