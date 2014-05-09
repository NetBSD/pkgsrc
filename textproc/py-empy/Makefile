# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:22 wiz Exp $

DISTNAME=	empy-3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://www.alcyone.com/software/empy/

MAINTAINER=	anthony.mallet@laas.fr
HOMEPAGE=	http://www.alcyone.com/software/empy/
COMMENT=	Powerful and robust templating system for Python
LICENSE=	gnu-lgpl-v2.1

INSTALLATION_DIRS=	bin share/doc
REPLACE_PYTHON+=        em.py

USE_TOOLS+=		pax
PYDISTUTILSPKG=		# yes
PLIST_SUBST+=		PYVERSSUFFIX="${PYVERSSUFFIX}"

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

# Fix html path in documentation
SUBST_CLASSES+=		doc
SUBST_STAGE.doc=	post-configure
SUBST_FILES.doc=	doc/index.html
SUBST_FILES.doc+=	doc/home/max/projects/empy/doc/em.html
SUBST_SED.doc=		-e "s|home/max/projects/empy/doc/||g"
SUBST_SED.doc+=		-e "s|../../../../../||g"
SUBST_MESSAGE.doc=	Fixing paths in documentation

post-install: install-wrapper install-doc

.PHONY: install-wrapper
install-wrapper:
	${INSTALL_SCRIPT} ${WRKSRC}/em.py \
		${DESTDIR}${PREFIX}/bin/empy-${PYVERSSUFFIX}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf empy-${PYVERSSUFFIX} empy

.PHONY: install-doc
install-doc:
	cd ${WRKSRC}/doc/home/max/projects/empy/doc/ && \
	${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/empy
	${CP} ${WRKSRC}/doc/index.html ${DESTDIR}${PREFIX}/share/doc/empy/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
