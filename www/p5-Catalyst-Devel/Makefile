# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:16:36 abs Exp $

DISTNAME=	Catalyst-Devel-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Devel/
COMMENT=	Development tool kit for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Config-General>=0:../../devel/p5-Config-General
DEPENDS+=	p5-Path-Class>=0.09:../../devel/p5-Path-Class
DEPENDS+=       p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Catalyst-Action-RenderView>=0.04:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple>=0.16:../../www/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader>=0:../../www/p5-Catalyst-Plugin-ConfigLoader
DEPENDS+=	p5-YAML>=0.55:../../textproc/p5-YAML
DEPENDS+=	p5-parent>=0:../../devel/p5-parent
DEPENDS+=	p5-File-Copy-Recursive>=0:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-Catalyst-Manual>=5.70:../../www/p5-Catalyst-Manual
DEPENDS+=	p5-Catalyst-Plugin-StackTrace>=0:../../www/p5-Catalyst-Plugin-StackTrace

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Devel/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
