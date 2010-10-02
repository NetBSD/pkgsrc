# $NetBSD: Makefile,v 1.3 2010/10/02 08:58:56 obache Exp $

DISTNAME=	compass-0.10.5
PKGREVISION=	1
CATEGORIES=	www
#MASTER_SITES=	http://gems.github.com/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=3.0.0:../../textproc/ruby-haml

CONFLICTS+=	ruby[1-9][0-9]-compass-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
