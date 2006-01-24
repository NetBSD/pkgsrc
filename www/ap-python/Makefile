# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:42 wiz Exp $
#

DISTNAME=		mod_python-2.7.10
PKGNAME=		ap-python-2.7.10
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Python interpreter embedded into Apache

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON_BIN=${PYTHONBIN:Q}
MAKE_ENV+=		PYTHONBIN=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED=	23 22 21 20

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
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
