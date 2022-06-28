# $NetBSD: Makefile,v 1.29 2022/06/28 11:37:18 wiz Exp $

DISTNAME=	Catalyst-View-JSON-0.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-View-JSON
COMMENT=	JSON view for your data in Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-JSON-MaybeXS>=1.003003:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/View/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
