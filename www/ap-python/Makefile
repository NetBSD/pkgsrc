# $NetBSD: Makefile,v 1.3 2002/09/21 23:47:00 jlam Exp $
#

DISTNAME=		mod_python-2.7.6
PKGNAME=		ap-python-2.7.6
CATEGORIES=		www
MASTER_SITES=		http://www.modpython.org/dist/
EXTRACT_SUFX=           .tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.modpython.org/
COMMENT=		Python interpretter embedded into Apache

DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON_BIN=${PYTHONBIN}
MAKE_ENV+=		PYTHONBIN=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED=	20

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ap-mod_python
	( cd ${WRKSRC}; ${PAX} -r -w -s /doc-html/ap-mod_python/ \
		-p e doc-html ${PREFIX}/share/doc/html )
	${ECHO} lib/httpd/mod_python.so >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/mod_python \
		share/doc/html/ap-mod_python \
		-type f -print >>${PLIST_SRC} )
	( cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/mod_python \
		share/doc/html/ap-mod_python \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC} )

.include "../../lang/python/extension.mk"
.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
