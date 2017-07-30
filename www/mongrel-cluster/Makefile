# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:25 wiz Exp $

DISTNAME=	mongrel_cluster-1.0.5
PKGREVISION=	1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fauna/mongrel
COMMENT=	Mongrel plugin to manage a mongrel cluster
LICENSE=	gnu-gpl-v2 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-gem_plugin>=0.2.3:../../misc/ruby-gem_plugin
DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=1.0.2:../../www/mongrel

CONFLICTS+=	ruby[1-9][0-9]-mongrel-cluster-[0-9]* mongrel-cluster-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
