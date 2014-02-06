# $NetBSD: Makefile,v 1.15 2014/02/06 12:01:58 abs Exp $

DISTNAME=	Catalyst-Authentication-Store-DBIx-Class-0.1505
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Authentication-Store-DBIx-Class/
COMMENT=	Storage class for Catalyst Authentication using DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0.18:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10008:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime>=5.80000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-DBIx-Class>=0.08000:../../databases/p5-DBIx-Class
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PERL5_PACKLIST=		auto/Catalyst/Authentication/Store/DBIx/Class/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
