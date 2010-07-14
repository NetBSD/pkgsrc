# $NetBSD: Makefile,v 1.4 2010/07/14 13:25:34 obache Exp $

DISTNAME=	ruby-xslt-0.9.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://raa.ruby-lang.org/project/ruby-xslt/
COMMENT=	Ruby wrapper classes for libxslt
LICENSE=	gnu-gpl-v2

GEM_BUILD=	gemspec
CONFIGURE_ARGS=	--with-xslt-dir=${BUILDLINK_PREFIX.libxslt}

.include "../../misc/rubygems/rubygem.mk"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
