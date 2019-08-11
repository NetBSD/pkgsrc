# $NetBSD: Makefile,v 1.20 2019/08/11 13:24:33 wiz Exp $

DISTNAME=	Catalyst-Plugin-StackTrace-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-StackTrace
COMMENT=	Display a stack trace on the debug screen
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Devel-StackTrace>=0:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Plugin/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
