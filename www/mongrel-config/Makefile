# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:25 wiz Exp $

DISTNAME=	mongrel_config-0.3.1
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fauna/mongrel
COMMENT=	Mongrel web-based configuration tool
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel
DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin
DEPENDS+=	${RUBY_PKGPREFIX}-camping>=1.5:../../www/camping

CONFLICTS+=	ruby[1-9][0-9]-mongrel-config-[0-9]* mongrel-config-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
