# $NetBSD: Makefile,v 1.7 2009/06/11 10:42:44 sno Exp $

DISTNAME=	Catalyst-Devel-1.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Devel/
COMMENT=	Development tool kit for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Action-RenderView>=0.04:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Manual>=5.70:../../www/p5-Catalyst-Manual
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader-[0-9]*:../../www/p5-Catalyst-Plugin-ConfigLoader
#DEPENDS+=	p5-Catalyst-Plugin-StackTrace-[0-9]*:../../www/p5-Catalyst-Plugin-StackTrace
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple>=0.16:../../www/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-Runtime>=5.80000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-General>=2.42:../../devel/p5-Config-General
DEPENDS+=	p5-File-ChangeNotify>=0.03:../../devel/p5-File-ChangeNotify
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Module-Install>=0.64:../../devel/p5-Module-Install
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=       p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Catalyst/Devel/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
