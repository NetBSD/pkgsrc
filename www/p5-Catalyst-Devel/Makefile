# $NetBSD: Makefile,v 1.17 2011/08/14 16:05:47 obache Exp $

DISTNAME=	Catalyst-Devel-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Devel/
COMMENT=	Development tool kit for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Action-RenderView>=0.10:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader>=0.23:../../www/p5-Catalyst-Plugin-ConfigLoader
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple>=0.28:../../www/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-Runtime>=5.80015:../../www/p5-Catalyst-Runtime
#DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-General>=2.42:../../devel/p5-Config-General
DEPENDS+=	p5-File-ChangeNotify>=0.07:../../devel/p5-File-ChangeNotify
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Module-Install>=0.91:../../devel/p5-Module-Install
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast-[0-9]*:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	{perl>=5.12.0,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Catalyst/Devel/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
