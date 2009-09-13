# $NetBSD: Makefile,v 1.2 2009/09/13 20:28:08 sno Exp $

DISTNAME=	Catalyst-Action-REST-0.77
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Action-REST/
COMMENT=	Automated REST Method Dispatching
LICENSE=	${PERL5_LICENSE}

DEPENDS+= p5-Catalyst-Runtime>=5.7001:../../www/p5-Catalyst-Runtime
DEPENDS+= p5-Class-Inspector>=1.13:../../devel/p5-Class-Inspector
DEPENDS+= p5-Data-Serializer>=0.36:../../devel/p5-Data-Serializer
DEPENDS+= p5-libwww>=5.831:../../www/p5-libwww
DEPENDS+= p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat
DEPENDS+= {perl>=5.10,p5-Module-Pluggable>=0}:../../devel/p5-Module-Pluggable
DEPENDS+= p5-Params-Validate>=0.76:../../devel/p5-Params-Validate
DEPENDS+= p5-URI-Find>=0:../../www/p5-URI-Find
DEPENDS+= p5-YAML-Syck>=0.67:../../textproc/p5-YAML-Syck

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Action/REST/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
