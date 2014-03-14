# $NetBSD: Makefile,v 1.15 2014/03/14 18:09:53 taca Exp $

DISTNAME=	haml-4.0.5
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9][0-9]-haml-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
