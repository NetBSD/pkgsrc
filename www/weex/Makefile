# $NetBSD: Makefile,v 1.5 2003/07/22 04:14:40 martti Exp $

DISTNAME=	weex-2.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.enjoy.ne.jp/~gm/program/weex/arc/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.enjoy.ne.jp/~gm/program/weex/index.html
COMMENT=	Non-interactive ftp client

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

WEEX_DOCS=	AUTHORS BUGS BUGS.ja COPYING COPYING.ja \
		ChangeLog ChangeLog.ja FAQ FAQ.ja README README.ja \
		THANKS TODO TODO.ja

WEEX_DOCDIR=	share/doc/weex

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/${WEEX_DOCDIR}
.for f in ${WEEX_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${LOCALBASE}/${WEEX_DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/examples/weex
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc \
				${LOCALBASE}/share/examples/weex

.include "../../mk/bsd.pkg.mk"
