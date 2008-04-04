# $NetBSD: Makefile,v 1.2 2008/04/04 15:21:57 jlam Exp $

DISTNAME=	libxml-ruby-0.5.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libxml.rubyforge.org/
COMMENT=	libxml2 interface module for Ruby

GEM_BUILD=		gemspec
CONFIGURE_ARGS+=	\
	--with-xml2-include=${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../misc/rubygems/rubygem.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
