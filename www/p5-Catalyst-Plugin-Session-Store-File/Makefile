# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:19:54 abs Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-File-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Session::Store::File
COMMENT=	File storage backend for session data

DEPENDS+=	p5-Class-Data-Inheritable>=0:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=       p5-Cache-Class>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Catalyst-Plugin-Session>=0:../../www/p5-Catalyst-Plugin-Session

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/File/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
