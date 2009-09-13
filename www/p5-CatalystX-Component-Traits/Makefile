# $NetBSD: Makefile,v 1.3 2009/09/13 20:37:58 sno Exp $

DISTNAME=	CatalystX-Component-Traits-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-Component-Traits/
COMMENT=	Automatic Trait Loading and Resolution for Catalyst Components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80005:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose-Autobox-[0-9]*:../../devel/p5-Moose-Autobox
DEPENDS+=	p5-MooseX-Traits-Pluggable>=0.08:../../devel/p5-MooseX-Traits-Pluggable
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Module-Pluggable>=3.9:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CatalystX/Component/Traits/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
