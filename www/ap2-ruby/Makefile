# $NetBSD: Makefile,v 1.1.1.1 2003/07/21 17:43:53 taca Exp $

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap2-${RUBY_PKGNAMEPREFIX}${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Embedded Ruby for Apache2 (development version)

CONFLICTS+=	ap-ruby

USE_BUILDLINK2=	YES
DIST_SUBDIR=	ruby
USE_RUBY=	YES
RUBY_REQD=	1.6
VERSION=	1.1.1

HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-eruby-includes="${BUILDLINK_PREFIX.ruby-eruby}/include" \
		--with-eruby-libraries="${BUILDLINK_PREFIX.ruby-eruby}/lib"
MAKE_FLAGS+= APACHE_INCLUDES='-I${PREFIX}/include/httpd \
		-I${PREFIX}/include/apr-0'

post-build:
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKSRC}/examples/mod_ruby.conf

post-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/examples/mod_ruby.conf  \
		${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/doc/*  ${RUBY_DOCDIR}/mod_ruby

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../textproc/ruby-eruby/buildlink2.mk"
.include "../../devel/apr/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
