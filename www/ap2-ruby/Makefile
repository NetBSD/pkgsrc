# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:24 tv Exp $

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap2-${RUBY_PKGNAMEPREFIX}${VERSION}
PKGREVISION=	4
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Embedded Ruby for Apache2 (development version)

CONFLICTS+=	ap-ruby

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
APACHE_MODULE=	YES
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

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
CONF_FILES+=		${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
			${PKG_SYSCONFDIR}/mod_ruby.conf

post-build:
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKSRC}/examples/mod_ruby.conf

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/doc/*  ${RUBY_DOCDIR}/mod_ruby
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/examples/mod_ruby.conf  \
		${RUBY_EXAMPLESDIR}/mod_ruby

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../textproc/ruby-eruby/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
