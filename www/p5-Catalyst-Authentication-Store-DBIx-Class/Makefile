# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:15:21 abs Exp $

DISTNAME=	Catalyst-Authentication-Store-DBIx-Class-0.104
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Authentication::Store::DBIx::Class
COMMENT=	Storage class for Catalyst Authentication using DBIx::Class

DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10005:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=     	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Authentication/Store/DBIx/Class/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
