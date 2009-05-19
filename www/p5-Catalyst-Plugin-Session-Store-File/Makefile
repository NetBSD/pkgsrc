# $NetBSD: Makefile,v 1.6 2009/05/19 06:49:30 sno Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-File-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Session::Store::File
COMMENT=	File storage backend for session data
LICENSE=	gnu-gpl-v2 # OR packages

DEPENDS+=	p5-Cache-Cache>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.21:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Runtime>=5.7000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-MRO-Compat>=0.10:../../devel/p5-MRO-Compat

PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/File/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
