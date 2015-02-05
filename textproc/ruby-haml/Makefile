# $NetBSD: Makefile,v 1.16 2015/02/05 15:04:31 taca Exp $

DISTNAME=	haml-4.0.6
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

CONFLICTS+=	ruby[1-9][0-9][0-9]-haml-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
