# $NetBSD: Makefile,v 1.1.1.1 2004/03/12 05:12:09 taca Exp $

DISTNAME=		${RUBY_PKGNAMEPREFIX}fcgi-${VER}
CATEGORIES=		www devel
MASTER_SITES=   	http://www.moonwolf.com/ruby/archive/

MAINTAINER=		rasputnik@hellooperator.net
HOMEPAGE=		http://rwiki.moonwolf.com/rw-cgi.cgi?cmd=view;name=fcgi
COMMENT=		FastCGI interface for Ruby

USE_BUILDLINK2=		# defined

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
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../www/fcgi/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
