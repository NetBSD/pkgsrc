# $NetBSD: Makefile,v 1.16 2004/04/24 22:17:12 snj Exp $

DISTNAME=	FXRuby-1.0.25
PKGNAME=	${RUBY_PKGNAMEPREFIX}fox-1.0.25
PKGREVISION=			1
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fxruby/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://fxruby.sourceforge.net/
COMMENT=	Ruby interface to FOX GUI library

DEPENDS+=	ruby-opengl-[0-9]*:../../graphics/ruby-opengl
WRKDIST=	${WRKDIR}/${DISTNAME}

WRKSRC=		${WRKDIST}/ext/fox
USE_BUILDLINK3=	yes
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= # defined
CONFIGURE_ARGS+= --with-fox-include=${BUILDLINK_PREFIX.fox}/include/fox
CONFIGURE_ARGS+= --with-opengl-include=${BUILDLINK_PREFIX.Mesa}/include/GL
CONFIGURE_ARGS+= --with-fox-lib=${BUILDLINK_PREFIX.fox}/lib

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
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fox ${RUBY_DOCDIR}/fox/images
	${INSTALL_DATA} ${WRKDIST}/doc/*.html ${RUBY_DOCDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/doc/images/* ${RUBY_DOCDIR}/fox/images

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
