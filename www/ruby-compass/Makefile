# $NetBSD: Makefile,v 1.2 2010/09/10 12:58:46 taca Exp $

DISTNAME=	compass-0.10.5
CATEGORIES=	www
#MASTER_SITES=	http://gems.github.com/gems/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/
COMMENT=	Stylesheet authoring framework based on Sass
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-haml>=3.0.0:../../textproc/ruby-haml

CONFLICTS+=	ruby[1-9][0-9]-compass-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
