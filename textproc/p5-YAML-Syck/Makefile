# $NetBSD: Makefile,v 1.19 2013/05/31 12:42:23 wiz Exp $

DISTNAME=	YAML-Syck-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~audreyt/YAML-Syck/
COMMENT=	Fast, lightweight YAML loader and dumper
LICENSE=	mit AND 2-clause-bsd

USE_LANGUAGES=	c
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/Syck/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
