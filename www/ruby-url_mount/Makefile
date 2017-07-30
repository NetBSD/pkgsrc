# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:28 wiz Exp $

DISTNAME=	url_mount-0.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hassox/url_mount/
COMMENT=	Universal mounting points for rack applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	23 22 24

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
