# $NetBSD: Makefile,v 1.3 2008/06/19 15:21:35 taca Exp $

DISTNAME=	libxml-ruby-0.5.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
PKGREVISION=	1
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
