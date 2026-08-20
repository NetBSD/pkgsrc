# $NetBSD: Makefile,v 1.33 2026/08/20 21:05:39 wiz Exp $

DISTNAME=	Catalyst-Plugin-Static-Simple-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

PATCHFILES+=	CVE-2026-15743-r1.patch
PATCH_SITES=	https://security.metacpan.org/patches/C/Catalyst-Plugin-Static-Simple/0.38/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Catalyst::Plugin::Static::Simple
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
