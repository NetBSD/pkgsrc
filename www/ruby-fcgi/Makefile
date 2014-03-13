# $NetBSD: Makefile,v 1.17 2014/03/13 11:08:53 jperkin Exp $

DISTNAME=		fcgi-0.8.8
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fcgi.rubyforge.org/wiki/wiki.pl
COMMENT=		FastCGI interface for Ruby
LICENSE=		gnu-gpl-v2 OR ruby-license

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	--with-fcgi-dir=${BUILDLINK_PREFIX.fcgi:Q}

.include "../../lang/ruby/gem.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
