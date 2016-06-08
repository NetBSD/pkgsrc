# $NetBSD: Makefile,v 1.39 2016/06/08 19:25:19 wiz Exp $

DISTNAME=	Alien-wxWidgets-0.67
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Alien-wxWidgets/
COMMENT=	Building, finding and using wxWidgets binaries
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-ExtUtils-CBuilder>=0.24}:../../devel/p5-ExtUtils-CBuilder
DEPENDS+=	p5-Module-Pluggable>=2.6:../../devel/p5-Module-Pluggable

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Alien/wxWidgets/.packlist
PERL5_MODULE_TYPE=	Module::Build
MAKE_PARAMS+=		--no-wxWidgets-build

.include "../../lang/perl5/module.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
