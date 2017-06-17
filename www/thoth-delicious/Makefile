# $NetBSD: Makefile,v 1.8 2017/06/17 05:08:29 taca Exp $

DISTNAME=	thoth_delicious-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# Web site has gone: http://thothblog.org/
COMMENT=	Thoth blog engine del.icio.us plugin
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-thoth>=0.1.0:../../www/thoth

OVERRIDE_GEMSPEC+=	thoth>=0.1.0
OVERRIDE_GEMSPEC+=	json_pure:json>=1.1.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
