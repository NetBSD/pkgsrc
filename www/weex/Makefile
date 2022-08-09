# $NetBSD: Makefile,v 1.17 2022/08/09 12:08:32 jperkin Exp $

DISTNAME=	weex-2.6.1.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=weex/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://weex.sourceforge.net/
COMMENT=	Non-interactive ftp client

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

WEEX_DOCS=	AUTHORS BUGS BUGS.ja COPYING COPYING.ja \
		ChangeLog ChangeLog.ja FAQ FAQ.ja README README.ja \
		THANKS TODO TODO.ja

WEEX_DOCDIR=	share/doc/weex

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DG_VA_COPY=va_copy

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${WEEX_DOCDIR}
.for f in ${WEEX_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/${WEEX_DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/weex
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc \
				${DESTDIR}${PREFIX}/share/examples/weex

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
