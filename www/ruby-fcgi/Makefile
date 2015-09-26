# $NetBSD: Makefile,v 1.19 2015/09/26 23:44:03 taca Exp $

DISTNAME=		fcgi-0.9.2.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		devel www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/alphallc/ruby-fcgi-ng
COMMENT=		FastCGI interface for Ruby
LICENSE=		gnu-gpl-v2 OR ruby-license

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	--with-fcgi-dir=${BUILDLINK_PREFIX.fcgi:Q}
OVERRIDE_GEMSPEC+=	:files ext/fcgi/Makefile=

pre-configure:
	${RM} -f ${WRKSRC}/ext/fcgi/Makefile

.include "../../lang/ruby/gem.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
