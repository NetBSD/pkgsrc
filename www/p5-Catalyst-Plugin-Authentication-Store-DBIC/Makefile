# $NetBSD: Makefile,v 1.6 2011/08/14 16:05:48 obache Exp $

DISTNAME=	Catalyst-Plugin-Authentication-Store-DBIC-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Authentication::Store::DBIC
COMMENT=	Authentication and authorization against a DBIx::Class or CDBI

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.06:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Set-Object>=1.14:../../devel/p5-Set-Object
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles>=0.03:../../www/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie>=0.02:../../www/p5-Catalyst-Plugin-Session-State-Cookie

PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/Store/DBIC/.packlist

MAKE_ENV+=      PERL_EXTUTILS_AUTOINSTALL=--skipdeps

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
