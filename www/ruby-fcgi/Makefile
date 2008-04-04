# $NetBSD: Makefile,v 1.13 2008/04/04 15:30:02 jlam Exp $

DISTNAME=		fcgi-0.8.7
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sugi.nemui.org/prod/ruby-fcgi/
COMMENT=		FastCGI interface for Ruby

GEM_BUILD=		gemspec
CONFIGURE_ARGS+=	--with-fcgi-dir=${BUILDLINK_PREFIX.fcgi:Q}

.include "../../misc/rubygems/rubygem.mk"

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
