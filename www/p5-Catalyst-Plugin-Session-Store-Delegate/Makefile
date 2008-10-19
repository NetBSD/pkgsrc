# $NetBSD: Makefile,v 1.2 2008/10/19 19:19:06 he Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-Delegate-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Session::Store::Delegate
COMMENT=	Delegate session storage to an application model object

DEPENDS+=       p5-Test-use-ok>=0:../../devel/p5-Test-use-ok
DEPENDS+=       p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=       p5-Catalyst-Plugin-Session>=0.12:../../www/p5-Catalyst-Plugin-Session

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/Delegate/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
