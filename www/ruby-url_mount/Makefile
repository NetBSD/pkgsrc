# $NetBSD: Makefile,v 1.2 2017/06/05 03:29:38 taca Exp $

DISTNAME=	url_mount-0.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/hassox/url_mount/
COMMENT=	Universal mounting points for rack applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	23 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
