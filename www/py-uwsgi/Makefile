# $NetBSD: Makefile,v 1.2 2010/02/10 13:25:03 joerg Exp $
#

DISTNAME=	uwsgi-0.9.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		gnu-gpl-v2

CFLAGS.python=		${PYTHONCONFIG} --cflags
LDFLAGS.python=		${PYTHONCONFIG} --ldflags
CFLAGS.libxml2=		xml2-config --cflags
LDFLAGS.libxml2=	xml2-config --libs

INSTALLATION_DIRS+=	bin

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=		-Wl,-rpath,${PREFIX}/lib -L${PREFIX}/lib
do-build:
	cd ${WRKSRC} && \
	    ${CC} -o uwsgi ${CFLAGS} ${CFLAGS.python:sh} ${CFLAGS.libxml2:sh} \
	    protocol.c socket.c spooler.c utils.c uwsgi.c uwsgi_pymodule.c \
	    ${LDFLAGS} ${LDFLAGS.python:sh} ${LDFLAGS.libxml2:sh}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uwsgi ${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
