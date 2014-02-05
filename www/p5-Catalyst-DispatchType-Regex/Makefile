# $NetBSD: Makefile,v 1.1.1.1 2014/02/05 21:46:21 abs Exp $

DISTNAME=	Catalyst-DispatchType-Regex-5.90033
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-DispatchType-Regex/
COMMENT=	Deprecated Catalyst Regex DispatchType
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Text-SimpleTable>=0:../../textproc/p5-Text-SimpleTable

BUILD_DEPENDS+=	p5-Module-Build>=0.4004:../../devel/p5-Module-Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/DispatchType/Regex/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
