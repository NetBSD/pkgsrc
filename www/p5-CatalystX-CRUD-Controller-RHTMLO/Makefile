# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:31:27 abs Exp $

DISTNAME=	CatalystX-CRUD-Controller-RHTMLO-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?CatalystX::CRUD::Controller::RHTMLO
COMMENT=	Rose::HTML::Objects CRUD controller

DEPENDS+=       p5-CatalystX-CRUD>=0.26:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-Rose-HTML-Objects>=0:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/Controller/RHTMLO/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
