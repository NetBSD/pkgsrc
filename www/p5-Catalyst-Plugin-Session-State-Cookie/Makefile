# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:18:48 abs Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Plugin::Session::State::Cookie
COMMENT=	Maintain session IDs using cookies

DEPENDS+=	p5-Catalyst-Runtime>=5.7010:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.19:../../www/p5-Catalyst-Plugin-Session

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/State/Cookie/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
