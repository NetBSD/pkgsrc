# $NetBSD: Makefile,v 1.4.2.1 2002/06/23 19:06:50 jlam Exp $

DISTNAME=	FXRuby-0.99.174
PKGNAME=	${RUBY_PKGNAMEPREFIX}fox-0.99.174
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fxruby/}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://fxruby.sourceforge.net/
COMMENT=	Ruby interface to FOX GUI library

DEPENDS+=	ruby-opengl-[0-9]*:../../graphics/ruby-opengl
# restore next line on next update, delete the line after
#BUILDLINK_DEPENDS.fox=${DISTNAME:C/FXRuby/fox/}
BUILDLINK_DEPENDS.fox=fox-0.99.174nb1

WRKDIST=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIST}/ext/fox

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF=#defined
CONFIGURE_ARGS+=--with-fox-include=${BUILDLINK_DIR}/include/fox
CONFIGURE_ARGS+=--with-opengl-include=${BUILDLINK_DIR}/include/GL
CONFIGURE_ARGS+=--with-fox-lib=${BUILDLINK_DIR}/lib

INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/lib/fox/*.rb ${RUBY_SITELIBDIR}/fox
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/examples/README ${WRKDIST}/examples/*.rb ${RUBY_EXAMPLESDIR}/fox
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/icons
	${INSTALL_DATA} ${WRKDIST}/examples/icons/* \
		${RUBY_EXAMPLESDIR}/fox/icons
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/textedit
	${INSTALL_DATA} ${WRKDIST}/examples/textedit/* \
		${RUBY_EXAMPLESDIR}/fox/textedit
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/tests
	${INSTALL_DATA} ${WRKDIST}/tests/* ${RUBY_EXAMPLESDIR}/fox/tests
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/doc/* ${RUBY_DOCDIR}/fox

.include "../../x11/fox/buildlink.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
