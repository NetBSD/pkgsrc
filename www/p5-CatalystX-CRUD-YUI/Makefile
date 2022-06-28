# $NetBSD: Makefile,v 1.26 2022/06/28 11:37:18 wiz Exp $

DISTNAME=	CatalystX-CRUD-YUI-0.031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CatalystX-CRUD-YUI
COMMENT=	YUI for your CatalystX::CRUD view
LICENSE=	${PERL5_LICENSE}

# Recommended dependencies
DEPENDS+=	p5-CatalystX-CRUD-Model-RDBO>=0.20:../../databases/p5-CatalystX-CRUD-Model-RDBO
DEPENDS+=	p5-CatalystX-CRUD-ModelAdapter-DBIC>=0.08:../../databases/p5-CatalystX-CRUD-ModelAdapter-DBIC
DEPENDS+=	p5-DBIx-Class-RDBOHelpers>=0.08:../../databases/p5-DBIx-Class-RDBOHelpers
DEPENDS+=	p5-Rose-DBx-Object-MoreHelpers>=0.06:../../databases/p5-Rose-DBx-Object-MoreHelpers

# Required dependencies
DEPENDS+=	p5-Catalyst-Action-RenderView-[0-9]*:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader-[0-9]*:../../www/p5-Catalyst-Plugin-ConfigLoader
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple-[0-9]*:../../www/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-View-TT-[0-9]*:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-CatalystX-CRUD>=0.43:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-CatalystX-CRUD-Controller-RHTMLO>=0.19:../../www/p5-CatalystX-CRUD-Controller-RHTMLO
DEPENDS+=	p5-CatalystX-CRUD-View-Excel>=0.06:../../www/p5-CatalystX-CRUD-View-Excel
DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Config-General-[0-9]*:../../devel/p5-Config-General
DEPENDS+=	p5-JSON-XS>=2.23:../../converters/p5-JSON-XS
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Rose-HTMLx-Form-Related>=0.17:../../www/p5-Rose-HTMLx-Form-Related
DEPENDS+=	{p5-Template-Toolkit<=2.21,p5-Template-Plugin-Autoformat-[0-9]*}:../../textproc/p5-Template-Plugin-Autoformat
DEPENDS+=	p5-Template-Plugin-Handy>=0.002:../../devel/p5-Template-Plugin-Handy
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CatalystX/CRUD/YUI/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
