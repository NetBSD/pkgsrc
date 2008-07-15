# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:19:05 abs Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-DBIC-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Session::Store::DBIC
COMMENT=	DBIC session storage backend

DEPENDS+=	p5-Catalyst-Runtime>=5.65:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.09:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Plugin-Session-Store-Delegate>=0.02:../../www/p5-Catalyst-Plugin-Session-Store-Delegate
DEPENDS+=       p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBIx-Class>=0.07000:../../databases/p5-DBIx-Class
DEPENDS+=       p5-NEXT>=0:../../devel/p5-NEXT

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/DBIC/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
