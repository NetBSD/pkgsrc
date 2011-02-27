# $NetBSD: Makefile,v 1.6.2.1 2011/02/27 00:26:29 tron Exp $

DISTNAME=	ruby-xslt-0.9.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/glejeune/ruby-xslt
COMMENT=	Ruby wrapper classes for libxslt
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS=	--with-xslt-dir=${BUILDLINK_PREFIX.libxslt}

.include "../../lang/ruby/gem.mk"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
