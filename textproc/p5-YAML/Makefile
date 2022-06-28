# $NetBSD: Makefile,v 1.61 2022/06/28 11:36:46 wiz Exp $

DISTNAME=	YAML-1.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/YAML
COMMENT=	YAML implementation for Perl
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-YAML>=1.05:../../textproc/p5-Test-YAML
BUILD_DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Base>=0:../../devel/p5-Test-Base

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/YAML/.packlist
MAKE_PARAMS+=		< /dev/null
# By using Module::Install::Bundled a circular dependency on
# involving devel/p5-Module-Build, textproc/p5-YAML and
# devel/p5-Module-Install is avoided
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
