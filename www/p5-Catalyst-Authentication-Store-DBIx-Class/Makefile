# $NetBSD: Makefile,v 1.2 2008/10/19 19:19:06 he Exp $

DISTNAME=	Catalyst-Authentication-Store-DBIx-Class-0.104
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
