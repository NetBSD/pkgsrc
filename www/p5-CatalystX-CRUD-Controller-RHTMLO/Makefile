# $NetBSD: Makefile,v 1.7 2009/09/24 06:50:21 sno Exp $

DISTNAME=	CatalystX-CRUD-Controller-RHTMLO-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CatalystX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CatalystX-CRUD-Controller-RHTMLO/
COMMENT=	Rose::HTML::Objects CRUD controller

DEPENDS+=       p5-CatalystX-CRUD>=0.28:../../databases/p5-CatalystX-CRUD
DEPENDS+=	p5-Rose-HTML-Objects>=0:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CatalystX/CRUD/Controller/RHTMLO/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
