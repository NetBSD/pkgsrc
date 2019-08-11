# $NetBSD: Makefile,v 1.20 2019/08/11 13:24:31 wiz Exp $

DISTNAME=	Catalyst-Plugin-Authorization-Roles-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Authorization-Roles
COMMENT=	Role based authorization for Catalyst
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10003:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Set-Object>=1.14:../../devel/p5-Set-Object
DEPENDS+=	p5-UNIVERSAL-isa>=0.05:../../devel/p5-UNIVERSAL-isa

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Authorization/Roles/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
