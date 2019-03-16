# $NetBSD: Makefile,v 1.3 2019/03/16 14:14:48 taca Exp $
#

DISTNAME=	sass-listen-4.0.0
PKGREVISION=	1
CATEGORIES=	www devel ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sass/listen
COMMENT=	listens to file modifications and notifies

DEPENDS+=	${RUBY_PKGPREFIX}-rb-fsevent>=0.9.4:../../devel/ruby-rb-fsevent
DEPENDS+=	${RUBY_PKGPREFIX}-rb-inotify>=0.9.7:../../devel/ruby-rb-inotify

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
