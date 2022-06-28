# $NetBSD: Makefile,v 1.28 2022/06/28 11:37:17 wiz Exp $

DISTNAME=	Catalyst-Plugin-Static-Simple-0.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Static
COMMENT=	Serve static files with Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80008:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MIME-Types>=2.03:../../mail/p5-MIME-Types
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Plugin/Static/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
