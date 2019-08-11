# $NetBSD: Makefile,v 1.11 2019/08/11 13:24:30 wiz Exp $

DISTNAME=	Catalyst-DispatchType-Regex-5.90035
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-DispatchType-Regex
COMMENT=	Deprecated Catalyst Regex DispatchType
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
#DEPENDS+=	{perl>=5.7.3,p5-Text-Balanced>=0}:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Text-SimpleTable>=0:../../textproc/p5-Text-SimpleTable

#BUILD_DEPENDS+=	{perl>=5.19.1,p5-Module-Build>=0.4004}:../../devel/p5-Module-Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/DispatchType/Regex/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
