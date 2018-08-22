# $NetBSD: Makefile,v 1.25 2018/08/22 09:47:31 wiz Exp $

DISTNAME=	Catalyst-Action-REST-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Action-REST/
COMMENT=	Automated REST Method Dispatching
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80030:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Inspector>=1.13:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Config-General-[0-9]*:../../devel/p5-Config-General
DEPENDS+=	p5-Data-Serializer>=0.36:../../devel/p5-Data-Serializer
DEPENDS+=	p5-Data-Taxi-[0-9]*:../../devel/p5-Data-Taxi
DEPENDS+=	p5-FreezeThaw-[0-9]*:../../devel/p5-FreezeThaw
DEPENDS+=	p5-JSON>=2.12:../../converters/p5-JSON
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=1.03:../../devel/p5-Moose
DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
DEPENDS+=	p5-Params-Validate>=0.76:../../devel/p5-Params-Validate
DEPENDS+=	p5-URI-Find-[0-9]*:../../www/p5-URI-Find
DEPENDS+=	p5-YAML-Syck>=0.67:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-libwww>=5.831:../../www/p5-libwww
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Catalyst/Action/REST/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
