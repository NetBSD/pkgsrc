# $NetBSD: Makefile,v 1.7 2000/04/18 10:54:45 sakamoto Exp $
# FreeBSD Id: ports/x11-toolkits/ruby-gtk/Makefile,v 1.3 1999/08/31 02:59:33 peter Exp

DISTNAME=	ruby-gtk-0.23
CATEGORIES=	x11
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/ \
		ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/contrib/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/contrib/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/contrib/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/contrib/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/gtk/en/

DEPENDS+=	ruby-1.4.*:../../lang/ruby
DEPENDS+=	imlib-*:../../graphics/imlib

USE_X11=	YES
WRKSRC=		${WRKDIR}/${DISTNAME:S/ruby-//}
RUBY_VERSION=	1.4
PLIST_SUBST=	RUBY_VERSION=${RUBY_VERSION}

RUBY=		${PREFIX}/bin/ruby

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb)

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb ${PREFIX}/lib/ruby/${RUBY_VERSION}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/gtk
	${GTAR} Ccf ${WRKSRC}/sample - .|${GTAR} Cxf ${PREFIX}/share/examples/ruby/gtk -
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/gtk/browser
	${INSTALL_DATA} ${WRKSRC}/doc/*.rb ${PREFIX}/share/examples/ruby/gtk/browser
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ruby-gtk
	${GTAR} Ccf ${WRKSRC}/doc - .happy api api-ja|${GTAR} Cxf ${PREFIX}/share/doc/ruby-gtk -
.for f in BUGS MEMO-Imlib README README.EXT README.EXT.ja README.ja ToDo
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby-gtk
.endfor

.include "../../mk/bsd.pkg.mk"
