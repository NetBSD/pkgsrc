# $NetBSD: Makefile,v 1.7.4.1 2011/02/27 00:26:31 tron Exp $

DISTNAME=	thin-1.2.7
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.macournoyer.com/thin/
COMMENT=	Fast and very simple Ruby web server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=0.12.6:../../devel/ruby-eventmachine

CONFLICTS+=	ruby[1-9][0-9]-thin-[0-9]* thin-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
