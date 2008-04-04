# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:26:29 jlam Exp $

DISTNAME=	net-flickr-0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wonko.com/software/net-flickr/
COMMENT=	Flickr REST client

DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.5:../../textproc/ruby-hpricot

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
