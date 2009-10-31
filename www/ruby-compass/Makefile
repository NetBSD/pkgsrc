# $NetBSD: Makefile,v 1.1.1.1 2009/10/31 19:40:17 seb Exp $

DISTNAME=	chriseppstein-compass-0.8.17
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^chriseppstein-//}
CATEGORIES=	www
MASTER_SITES=	http://gems.github.com/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=2.2.0:../../textproc/ruby-haml

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
