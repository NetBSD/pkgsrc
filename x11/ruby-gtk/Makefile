# $NetBSD: Makefile,v 1.6 1999/12/14 07:23:20 sakamoto Exp $
# FreeBSD Id: ports/x11-toolkits/ruby-gtk/Makefile,v 1.3 1999/08/31 02:59:33 peter Exp

DISTNAME=	ruby-gtk-0.22
CATEGORIES=	x11
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/ \
		ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/contrib/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/contrib/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/contrib/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/contrib/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/gtk.html.en

DEPENDS+=	ruby-1.4.*:../../lang/ruby
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib

USE_X11=	YES
WRKSRC=		${WRKDIR}/gtk
RUBY_VERSION=	1.4
PLIST_SUBST=	RUBY_VERSION=${RUBY_VERSION}

RUBY=		${PREFIX}/bin/ruby

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb)

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb ${PREFIX}/lib/ruby/${RUBY_VERSION}
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${PREFIX}/share/examples/ruby/gtk
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk/browser
	${INSTALL_DATA} ${WRKSRC}/doc/*.rb ${PREFIX}/share/examples/ruby/gtk/browser
	${MKDIR} ${PREFIX}/share/examples/ruby/gtk/gdkimlib
	${INSTALL_DATA} ${WRKSRC}/sample/gdkimlib/*.rb ${PREFIX}/share/examples/ruby/gtk/gdkimlib

.include "../../mk/bsd.pkg.mk"
