# $NetBSD: Makefile,v 1.2 2019/02/25 09:20:53 jperkin Exp $
#

DISTNAME=	sass-listen-4.0.0
CATEGORIES=	www devel ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass/listen
COMMENT=	listens to file modifications and notifies

DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.4:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.7:../../sysutils/ruby-rb-inotify

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
