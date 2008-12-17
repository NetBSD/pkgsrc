# $NetBSD: Makefile,v 1.1.1.1 2008/12/17 01:16:19 he Exp $

DISTNAME=	CatalystX-CRUD-YUI-0.012
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD-YUI/
COMMENT=	YUI for your CatalystX::CRUD view

DEPENDS+=	p5-CatalystX-CRUD-Model-RDBO>=0.14:../../databases/p5-CatalystX-CRUD-Model-RDBO
DEPENDS+=	p5-CatalystX-CRUD-ModelAdapter-DBIC>=0.06:../../databases/p5-CatalystX-CRUD-ModelAdapter-DBIC
DEPENDS+=	p5-DBIx-Class-RDBOHelpers>=0.05:../../databases/p5-DBIx-Class-RDBOHelpers
DEPENDS+=	p5-Rose-DBx-Object-MoreHelpers>=0.02:../../databases/p5-Rose-DBx-Object-MoreHelpers
DEPENDS+=	p5-Catalyst-View-TT>=0:../../www/p5-Catalyst-View-TT
DEPENDS+=       p5-CatalystX-CRUD>=0.3:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-CatalystX-CRUD-Controller-RHTMLO>=0.17:../../www/p5-CatalystX-CRUD-Controller-RHTMLO
DEPENDS+=	p5-CatalystX-CRUD-View-Excel>=0.05:../../www/p5-CatalystX-CRUD-View-Excel
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=	p5-JSON-XS>=2:../../converters/p5-JSON-XS
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Rose-HTMLx-Form-Related>=0.07:../../www/p5-Rose-HTMLx-Form-Related
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Autoformat>=0:../../textproc/p5-Text-Autoformat/

BUILD_DEPENDS+=	p5-Template-Plugin-Handy>=0:../../devel/p5-Template-Plugin-Handy

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/YUI/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
