# $NetBSD: Makefile,v 1.3 2004/04/27 03:20:15 snj Exp $

DISTNAME=		${RUBY_PKGNAMEPREFIX}fcgi-${VER}
CATEGORIES=		www devel ruby
MASTER_SITES=   	http://www.moonwolf.com/ruby/archive/

MAINTAINER=		rasputnik@hellooperator.net
HOMEPAGE=		http://rwiki.moonwolf.com/rw-cgi.cgi?cmd=view;name=fcgi
COMMENT=		FastCGI interface for Ruby

USE_BUILDLINK3=		yes

VER=			0.8.4
CONFIGURE_ARGS=		-- --with-fcgi-dir=${PREFIX}
USE_RUBY_SETUP=		# defined
RUBY_SETUP=		install.rb
RUBY_EXTCONF_SUBDIRS=	ext/fcgi

DOCS=			README README.signals

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fcgi
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/fcgi
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
