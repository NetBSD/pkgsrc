# $NetBSD: Makefile,v 1.15.20.1 2013/07/16 17:00:51 tron Exp $

DISTNAME=		fcgi-0.8.8
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fcgi.rubyforge.org/wiki/wiki.pl
COMMENT=		FastCGI interface for Ruby
LICENSE=		gnu-gpl-v2 OR ruby-license

CONFIGURE_ARGS+=	--with-fcgi-dir=${BUILDLINK_PREFIX.fcgi:Q}

.include "../../lang/ruby/gem.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
