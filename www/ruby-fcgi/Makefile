# $NetBSD: Makefile,v 1.5 2004/11/28 05:45:05 taca Exp $

DISTNAME=		ruby-fcgi-${VER}
PKGNAME=		${RUBY_PKGPREFIX}-fcgi-${VER}
CATEGORIES=		www devel ruby
MASTER_SITES=   	http://www.moonwolf.com/ruby/archive/

MAINTAINER=		rasputnik@hellooperator.net
HOMEPAGE=		http://rwiki.moonwolf.com/rw-cgi.cgi?cmd=view;name=fcgi
COMMENT=		FastCGI interface for Ruby

USE_BUILDLINK3=		yes
USE_RUBY_SETUP=		yes
RUBY_SETUP=		install.rb
RUBY_EXTCONF_SUBDIRS=	ext/fcgi
VER=			0.8.5
CONFIGURE_ARGS=		-- --with-fcgi-dir=${PREFIX}
DOCS=			README README.signals

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fcgi
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/fcgi
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
