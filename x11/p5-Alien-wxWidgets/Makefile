# $NetBSD: Makefile,v 1.17 2012/09/07 19:17:49 adam Exp $

DISTNAME=	Alien-wxWidgets-0.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Alien-wxWidgets/
COMMENT=	Building, finding and using wxWidgets binaries
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	{perl>=5.10.1,p5-ExtUtils-CBuilder>=0.24}:../../devel/p5-ExtUtils-CBuilder

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++
PERL5_PACKLIST=		auto/Alien/wxWidgets/.packlist
PERL5_MODULE_TYPE=	Module::Build
MAKE_PARAMS+=		--no-wxWidgets-build

.include "../../lang/perl5/module.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
