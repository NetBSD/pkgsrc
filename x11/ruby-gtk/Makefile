# $NetBSD: Makefile,v 1.26 2004/04/24 22:21:39 snj Exp $
# FreeBSD: ports/x11-toolkits/ruby-gtk/Makefile,v 1.16 2000/10/15 15:45:59 knu Exp

DISTNAME=	ruby-gtk-0.25
PKGNAME=	${RUBY_PKGNAMEPREFIX}gtk-0.25
PKGREVISION=	5
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gnome/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-gnome.sourceforge.net/
COMMENT=	Ruby interface to Gtk+ toolkits

WRKSRC=		${WRKDIR}/${DISTNAME:S/ruby-//}
USE_BUILDLINK3=	yes

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install

DOCS_EN=	README README.EXT doc/rbbr.rb
DOCS_JA=	README.ja README.EXT.ja

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb)

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/gtk
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/doc
	${INSTALL_DATA} ${WRKSRC}/doc/rbbr.rb \
		${RUBY_EXAMPLESDIR}/gtk/doc
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/test
	${INSTALL_DATA} ${WRKSRC}/sample/test/* ${RUBY_EXAMPLESDIR}/gtk/test
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/testgtk
	${INSTALL_DATA} ${WRKSRC}/sample/testgtk/* \
		${RUBY_EXAMPLESDIR}/gtk/testgtk

.include "../../lang/ruby-base/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
