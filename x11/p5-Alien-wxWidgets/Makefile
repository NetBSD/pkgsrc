# $NetBSD: Makefile,v 1.67 2023/11/14 14:03:18 wiz Exp $

DISTNAME=	Alien-wxWidgets-0.69
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	22
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-wxWidgets
COMMENT=	Building, finding and using wxWidgets binaries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable>=2.6:../../devel/p5-Module-Pluggable

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Alien/wxWidgets/.packlist
PERL5_MODULE_TYPE=	Module::Build
MAKE_PARAMS+=		--no-wxWidgets-build

.include "../../lang/perl5/module.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
