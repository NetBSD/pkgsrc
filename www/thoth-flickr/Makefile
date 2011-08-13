# $NetBSD: Makefile,v 1.3 2011/08/13 00:33:58 taca Exp $

DISTNAME=	thoth_flickr-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thothblog.org/
COMMENT=	Flickr plugin for the Thoth blog engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-net-flickr>=0.0.1<0.2:../../www/ruby-net-flickr
DEPENDS+=	${RUBY_PKGPREFIX}-thoth>=0.1.0:../../www/thoth

OVERRIDE_GEMSPEC+=	thoth>=0.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
