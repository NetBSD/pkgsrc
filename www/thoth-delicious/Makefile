# $NetBSD: Makefile,v 1.4 2011/11/08 15:37:35 taca Exp $

DISTNAME=	thoth_delicious-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thothblog.org/
COMMENT=	del.icio.us plugin for the Thoth blog engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.2:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-thoth>=0.1.0:../../www/thoth

OVERRIDE_GEMSPEC+=	json-pure>=1.1.2 thoth>=0.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
