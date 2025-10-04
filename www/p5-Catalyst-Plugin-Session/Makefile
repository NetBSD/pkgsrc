# $NetBSD: Makefile,v 1.44 2025/10/04 07:36:46 wen Exp $

DISTNAME=	Catalyst-Plugin-Session-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Session
COMMENT=	Generic Catalyst Session plugin
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.71001:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose>=0.76:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast>=0.00801:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-Object-Signature>=0:../../devel/p5-Object-Signature
DEPENDS+=	p5-namespace-clean>=0.10:../../devel/p5-namespace-clean
DEPENDS+=	p5-Crypt-SysRandom>=0:../../security/p5-Crypt-SysRandom

TOOL_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Plugin/Session/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
