# $NetBSD: Makefile,v 1.10 2012/10/03 21:58:42 wiz Exp $

DISTNAME=	CatalystX-Component-Traits-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-Component-Traits/
COMMENT=	Automatic Trait Loading and Resolution for Catalyst Components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80005:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	{perl>=5.10.1,p5-Module-Pluggable>=3.9}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-MooseX-Traits-Pluggable>=0.08:../../devel/p5-MooseX-Traits-Pluggable
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Module-Pluggable>=3.9}:../../devel/p5-Module-Pluggable
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CatalystX/Component/Traits/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
