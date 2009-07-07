# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 19:00:51 sno Exp $

DISTNAME=	CatalystX-Component-Traits-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-Component-Traits/
COMMENT=	Automatic Trait Loading and Resolution for Catalyst Components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80005:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Moose-Autobox-[0-9]*:../../devel/p5-Moose-Autobox
DEPENDS+=	p5-MooseX-Traits-Pluggable-[0-9]*:../../devel/p5-MooseX-Traits-Pluggable
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CatalystX/Component/Traits/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
