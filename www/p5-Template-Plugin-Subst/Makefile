# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:32 ryoon Exp $

DISTNAME=	Template-Plugin-Subst-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Subst/
COMMENT=	Substitution functionality for Template Toolkit templates
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Plugin/Subst/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
