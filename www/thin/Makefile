# $NetBSD: Makefile,v 1.15 2014/03/14 19:31:19 taca Exp $

DISTNAME=	thin-1.6.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.macournoyer.com/thin/
COMMENT=	Fast and very simple Ruby web server
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-daemons>=1.0.9:../../misc/ruby-daemons
DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

CONFLICTS+=	ruby[1-9][0-9]-thin-[0-9]* thin-[0-9]*

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
