# $NetBSD: Makefile,v 1.8 2003/12/03 09:44:10 darcy Exp $
#

DISTNAME=		mod_python-2.7.8
PKGNAME=		ap-python-2.7.8
CATEGORIES=		www
MASTER_SITES=	http://www.modpython.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Python interpretter embedded into Apache

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON_BIN=${PYTHONBIN}
MAKE_ENV+=		PYTHONBIN=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED=	20 21 22 23

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ap-mod_python
	cd ${WRKSRC} && ${PAX} -rw -s /doc-html/ap-mod_python/ \
		-pe doc-html ${PREFIX}/share/doc/html
	${ECHO} lib/httpd/mod_python.so >${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${PYSITELIB}/mod_python \
		share/doc/html/ap-mod_python \
		-type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${PYSITELIB}/mod_python \
		share/doc/html/ap-mod_python \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../lang/python/extension.mk"
.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
