# $NetBSD: Makefile,v 1.10 2026/09/01 19:31:20 ktnb Exp $

DISTNAME=	Alien-LibGumbo-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-LibGumbo
COMMENT=	Gumbo parser library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-Base-ModuleBuild-[0-9]*:../../devel/p5-Alien-Base-ModuleBuild
DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Alien/LibGumbo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
