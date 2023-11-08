# $NetBSD: Makefile,v 1.42 2023/11/08 13:21:09 wiz Exp $

DISTNAME=	libxml-ruby-4.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xml4r.github.io/libxml-ruby/
COMMENT=	Support module for libxml2 library
LICENSE=	mit

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	\
	--with-xml2-include=${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../lang/ruby/gem.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
