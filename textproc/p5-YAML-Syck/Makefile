# $NetBSD: Makefile,v 1.41.2.1 2026/08/01 20:05:55 maya Exp $

DISTNAME=	YAML-Syck-1.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TODDR/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/YAML::Syck
COMMENT=	Fast, lightweight YAML loader and dumper
LICENSE=	mit AND 2-clause-bsd

PERL5_PACKLIST=		auto/YAML/Syck/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

# https://github.com/cpan-authors/YAML-Syck/issues/218
EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
