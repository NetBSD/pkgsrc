# $NetBSD: Makefile,v 1.18 2015/02/05 15:46:57 taca Exp $

DISTNAME=		fcgi-0.9.2.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		devel www

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fcgi.rubyforge.org/wiki/wiki.pl
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
