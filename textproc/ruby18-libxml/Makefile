# $NetBSD: Makefile,v 1.1.1.1 2008/01/15 10:56:59 rillig Exp $
#

DISTNAME=	libxml-ruby-0.3.8.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/ruby-//}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/15237/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libxml.rubyforge.org/
COMMENT=	libxml2 interface module for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ext/xml

CONFIGURE_ARGS+=	--with-xml2-include=${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../lang/ruby/modules.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
