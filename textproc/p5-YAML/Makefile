# $NetBSD: Makefile,v 1.29 2013/05/31 12:42:23 wiz Exp $

DISTNAME=	YAML-0.84
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML/
COMMENT=	YAML implementation for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/YAML/.packlist
MAKE_PARAMS+=		< /dev/null
# By using Module::Install::Bundled a circular dependency on
# involving devel/p5-Module-Build, textproc/p5-YAML and
# devel/p5-Module-Install is avoided
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
