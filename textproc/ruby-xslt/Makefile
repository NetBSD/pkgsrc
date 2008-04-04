# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:22:29 jlam Exp $

DISTNAME=	ruby-xslt-0.9.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://raa.ruby-lang.org/project/ruby-xslt/
COMMENT=	Ruby wrapper classes for libxslt

GEM_BUILD=	gemspec
CONFIGURE_ARGS=	--with-xslt-dir=${BUILDLINK_PREFIX.libxslt}

.include "../../misc/rubygems/rubygem.mk"

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
