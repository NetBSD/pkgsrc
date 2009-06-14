# $NetBSD: Makefile,v 1.23 2009/06/14 22:58:10 joerg Exp $
#

DISTNAME=		mod_python-2.7.10
PKGNAME=		ap13-python-2.7.10
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Python interpreter embedded into Apache

USE_TOOLS+=	pax

CONFLICTS=	ap-python-[0-9]*

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON_BIN=${PYTHONBIN:Q} ac_cv_path_MKDEP=
MAKE_ENV+=		PYTHONBIN=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED=	23

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ap-mod_python
	cd ${WRKSRC} && pax -rw -s /doc-html/ap-mod_python/ \
		-pe doc-html ${PREFIX}/share/doc/html
	${ECHO} lib/httpd/mod_python.so >${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${PYSITELIB}/mod_python \
		share/doc/html/ap-mod_python \
		-type f -print >>${PLIST_SRC}

.include "../../lang/python/extension.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
