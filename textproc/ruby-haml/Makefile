# $NetBSD: Makefile,v 1.14 2013/09/15 16:16:26 taca Exp $

DISTNAME=	haml-4.0.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9][0-9]-haml-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
