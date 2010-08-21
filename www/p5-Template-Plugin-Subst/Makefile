# $NetBSD: Makefile,v 1.4 2010/08/21 16:37:07 seb Exp $

DISTNAME=	Template-Plugin-Subst-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Subst/
COMMENT=	s/// functionality for Template Toolkit templates
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Plugin/Subst/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
