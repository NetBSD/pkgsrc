# $NetBSD: Makefile,v 1.15 2012/09/27 13:09:11 taca Exp $

DISTNAME=	libxml-ruby-2.3.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libxml.rubyforge.org/
COMMENT=	Support module for libxml2 library
LICENSE=	mit

GEM_CLEANBUILD=	ext/libxml/*
CONFIGURE_ARGS+=	\
	--with-xml2-include=${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../lang/ruby/gem.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
