# $NetBSD: Makefile,v 1.3 2022/08/08 14:08:40 wiz Exp $

DISTNAME=	HTML-Gumbo-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RU/RUZ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Gumbo
COMMENT=	HTML5 parser based on gumbo C library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-LibGumbo-[0-9]*:../../www/p5-Alien-LibGumbo
BUILD_DEPENDS+=	p5-PkgConfig-[0-9]*:../../devel/p5-PkgConfig

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Gumbo/.packlist

USE_TOOLS+=	pkg-config

.include "../../lang/perl5/module.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
