# $NetBSD: Makefile,v 1.12 2010/09/23 21:42:45 sno Exp $

DISTNAME=	YAML-Syck-1.15
PKGNAME=	p5-${DISTNAME}
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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
