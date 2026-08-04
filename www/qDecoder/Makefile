# $NetBSD: Makefile,v 1.16 2026/08/04 20:29:19 wiz Exp $

DISTNAME=	qDecoder-9.0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/

MAINTAINER=	jypak@users.sourceforge.net
HOMEPAGE=	https://qdecoder.org/
COMMENT=	Web Application Interface for C/C++ (CGI Library)

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
INSTALLATION_DIRS=	include lib share/doc/qDecoder share/doc/qDecoder/html \
			share/examples/qDecoder share/examples/qDecoder/qDecoder-upload

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS CHANGES COPYING \
		qDecoder.jpg ${DESTDIR}${PREFIX}/share/doc/qDecoder
	cd ${WRKSRC}/src; ${INSTALL_DATA} qDecoder.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC}/doc/html; ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/doc/qDecoder/html
	cd ${WRKSRC}/examples; ${INSTALL_DATA} *.c *.conf s*.in \
		*.html ${DESTDIR}${PREFIX}/share/examples/qDecoder
	cd ${WRKSRC}/examples/qDecoder-upload; ${INSTALL_DATA} *.html *.js \
		${DESTDIR}${PREFIX}/share/examples/qDecoder/qDecoder-upload

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
